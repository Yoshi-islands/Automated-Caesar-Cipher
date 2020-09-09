#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"

/*
 *   Program name: copyrecords.c
 *   Author: Maaz Syed
 *   Last Update: March 9th, 2020
 *   Function: This is the main for all the functions in the third part
 *   Compilation: make file
 *   Execution: make file
 */

int main(int argc, char const *argv[])
{

    struct data record;
    FILE *fp;
    FILE *fp2;
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int *text_freq;

    char inputFile[20][20];
    char outputFile[20][20];
    char decodeFile[20][20];
    int inputBool = 0;
    int outputBool = 0;
    int decode = 0;
    int reverseBool = 0;
    int recordNum = 0;
    int length = 0;
    int length2 = 0;
    int length3 = 0;
    int count = 0;
    int size = 0;
    int shift = 0;
    int decode_value = 0;
    char shiftedChar;
    char anotherChar;
    char encodedString[24];
    char longEncode[144];

    /*Algorithm to check for flags, same as question 2*/
    if (argc == 0)
    {
        printf("Error\n");
        exit(1);
    }

    for (i = 0; i < argc; i++)
    {
        /*This is the case where there is no space after -F flag*/
        if ((argv[i][0] == '-') && (argv[i][1] == 'F') && (argv[i][2] != '\0'))
        {
            inputBool = 1;
            length = strlen(argv[i]);
            j = 2;

            /*Takes the part after the -flag and stores it into the array*/
            while (j < length)
            {
                inputFile[0][count] = argv[i][j];
                count++;
                j++;
            }
            inputFile[0][count] = '\0';
            argv[i] = " ";
        }

        /*This is the case that there is a space after the -F*/
        if ((strcmp(argv[i], "-F") == 0) && (argv[i][2] == '\0'))
        {
            inputBool = 1;
            length = strlen(argv[i + 1]);
            /*put contents with a for loop into the array*/
            for (j = 0; j < length; j++)
            {
                inputFile[0][j] = argv[i + 1][j];
            }
            inputFile[0][j] = '\0';
            argv[i] = " ";
        }

        /*This is the case where there is no space after -O flag*/
        if ((argv[i][0] == '-') && (argv[i][1] == 'O') && (argv[i][2] != '\0'))
        {
            outputBool = 1; /*True*/
            length2 = strlen(argv[i]);
            j = 0;
            count = 0; /*Resetting the variables to make sure they don't carry on*/
            j = 2;

            /*Takes the part after the -flag and stores it into the array*/
            while (j < length2)
            {
                outputFile[0][count] = argv[i][j];
                count++;
                j++;
            }
            outputFile[0][count] = '\0';
            argv[i] = " ";
        }

        /*This is the case where there is no space after -D flag*/
        if ((argv[i][0] == '-') && (argv[i][1] == 'D') && (argv[i][2] != '\0'))
        {
            decode = 1;
            length3 = strlen(argv[i]);
            j = 2;
            count = 0;

            /*Takes the part after the -flag and stores it into the array*/
            while (j < length3)
            {
                decodeFile[0][count] = argv[i][j];
                count++;
                j++;
            }
            decodeFile[0][count] = '\0';
            argv[i] = " ";
        }

        /*This is the case that there is a space after the -D*/
        if ((strcmp(argv[i], "-D") == 0) && (argv[i][2] == '\0'))
        {
            decode = 1;
            length3 = strlen(argv[i + 1]);
            /*put contents with a for loop into the array*/
            for (j = 0; j < length; j++)
            {
                decodeFile[0][j] = argv[i + 1][j];
            }
            decodeFile[0][j] = '\0';
            argv[i] = " ";
        }

        if ((strcmp(argv[i], "-r") == 0 && argv[i][2] == '\0') ||
            (argv[i][0] == '-' && argv[i][1] == 'r') || (argv[i][0] == '-' && argv[i][2] == 'r') ||
            (argv[i][0] == '-' && argv[i][3] == 'r') || (argv[i][0] == '-' && argv[i][4] == 'r') ||
            (argv[i][0] == '-' && argv[i][5] == 'r'))
        {
            reverseBool = 1;
        }
    }

    if (inputBool == 0 || strcmp(inputFile[0], outputFile[0]) == 0)
    {

        fprintf(stdout, "%s\n", "Error");
        exit(1);
    }

    printf("%s\n", inputFile[0]);
    fp = fopen(inputFile[0], "rb");

    /*We want to find out the number of records*/
    size = file_size(fp);
    recordNum = (size / 408);

    if (fp == NULL)
    {
        printf("File does not exist\n");
        exit(1);
    }

    if (outputBool == 1)
    {
        fp2 = fopen(outputFile[0], "wb"); /*Writing for binary*/

        if (fp2 == NULL)
        {
            printf("File does not exist\n");
            exit(1);
        }
    }

    /*If the decode flag is true then we need to compute some operations*/
    if (decode == 1)
    {
        printf("true\n");
        text_freq = create_freq_table();
        add_letters(text_freq, &decodeFile[0][0]);             /*add letters based on string*/
        shift = encode_shift(&decodeFile[0][0], text_freq, 0); /*Dont want to print this*/
        decode_value = to_decode(shift);
    }

    /*If we have the reverse flag when we want to start reading it backwards*/
    if (reverseBool == 1)
    {
        /*We want to start reading from a different part*/
        fseek(fp, -(recordNum) * sizeof(struct data), SEEK_CUR);
    }

    for (i = 0; i < recordNum; i++) /*Writes based on the number of records that are within the file*/
    {

        fread(&record, sizeof(struct data), 1, fp);

        /*But we have the D flag we need to encode*/
        if (decode == 1)
        {

            for (j = 0; record.shortString[j] != '\0'; j++)
            {

                shiftedChar = encode(record.shortString[j], decode_value);

                /*Create a string for the short string*/
                encodedString[j] = shiftedChar;
            }
            encodedString[j] = '\0';

            /*Replace the short string in the struct with the encoded string*/
            strcpy(record.shortString, encodedString);

            for (k = 0; record.longString[k] != '\0'; k++)
            {
                anotherChar = encode(record.longString[k], decode_value);
                longEncode[k] = anotherChar;
            }
            longEncode[k] = '\0';

            strcpy(record.longString, longEncode);
        }

        if (outputBool == 1)
        {
            fwrite(&record, sizeof(struct data), 1, fp);
        }
        else if (outputBool == 0) /*For stdout in terms of outputBool*/
        {

            printf("\n");
            printf("[Record #%d]\n", i + 1);
            printf("Short string: %s\n", record.shortString);
            printf("Doubles:\n");

            /*Print the doubles within the array*/
            for (m = 0; m < 24; m++)
            {
                printf("%f\n", record.doubles[m]);
            }

            printf("Long string: %s\n ", record.longString);
            printf("Integers:\n");

            for (m = 0; m < 12; m++)
            {
                printf("%d\n", record.integers[m]);
            }
            printf("\n");
        }
    }

    fclose(fp); /*Close since we will always have the -F file*/

    if (outputBool == 1)
    {
        fclose(fp2);
    }

    if (decode == 1)
    {
        free(text_freq);
        text_freq = NULL;
    }
    return 0;
}