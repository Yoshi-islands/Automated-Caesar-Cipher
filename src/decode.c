#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"

/*
 *   Program name: decode.c
 *   Author: Maaz Syed
 *   Last Update: March 9th, 2020
 *   Function: This is the main for all the function in the second part
 *   Compilation: make file
 *   Execution: make file
 */

int main(int argc, char const *argv[])
{

    int totalCharacters;
    char c;
    char *string;
    int *text_freq;
    int arrayCount = 0;
    int shift = 0;
    int decode_value = 0;
    int i = 0;
    int currentSize = 0;

    /*Variables related for the flags*/
    char inputFile[20][20];
    char outputFile[20][20];
    int j = 0;
    int count = 0;
    int length = 0;
    int length2 = 0;
    FILE *fp;
    FILE *fp0;
    FILE *fp2;
    int size = 0;
    int inputBool = 0; /*Booleans set to false by default*/
    int outputBool = 0;
    int sbool = 0;
    int Sbool = 0;
    int freqBool = 0;
    int chiBool = 0;
    int tempBool = 0;
    int suppress = 0;
    char shiftedChar;
    char x;

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

        /*This is the case where there is no space after -F flag*/
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

        /*This is the case that there is a space after the -O*/
        if ((strcmp(argv[i], "-O") == 0) && (argv[i][2] == '\0'))
        {
            outputBool = 1;
            length = strlen(argv[i + 1]);
            /*put contents with a for loop into the array*/
            for (j = 0; j < length; j++)
            {
                outputFile[0][j] = argv[i + 1][j];
            }
            outputFile[0][j] = '\0';
            argv[i] = " ";
        }

        /*case for the -s argument*/
        /*The following statements account for any placement of the flags*/
        if ((strcmp(argv[i], "-s") == 0 && argv[i][2] == '\0') ||
            (argv[i][0] == '-' && argv[i][1] == 's') || (argv[i][0] == '-' && argv[i][2] == 's') ||
            (argv[i][0] == '-' && argv[i][3] == 's') || (argv[i][0] == '-' && argv[i][4] == 's') ||
            (argv[i][0] == '-' && argv[i][5] == 's'))
        {
            sbool = 1; /*Will be printed later*/
        }

        if ((strcmp(argv[i], "-S") == 0 && argv[i][2] == '\0') || (argv[i][0] == '-' && argv[i][1] == 'S') ||
            (argv[i][0] == '-' && argv[i][2] == 'S') || (argv[i][0] == '-' && argv[i][3] == 'S') ||
            (argv[i][0] == '-' && argv[i][4] == 'S') ||
            (argv[i][0] == '-' && argv[i][5] == 'S'))
        {

            Sbool = 1; /*Will be printed later*/
        }

        if ((strcmp(argv[i], "-t") == 0 && argv[i][2] == '\0') ||
            (argv[i][0] == '-' && argv[i][1] == 't') || (argv[i][0] == '-' && argv[i][2] == 't') ||
            (argv[i][0] == '-' && argv[i][3] == 't') || (argv[i][0] == '-' && argv[i][4] == 't') ||
            (argv[i][0] == '-' && argv[i][5] == 't'))

        {

            freqBool = 1; /*Just for printing will be computed either way*/
        }

        if ((strcmp(argv[i], "-x") == 0 && argv[i][2] == '\0') ||
            (argv[i][0] == '-' && argv[i][1] == 'x') || (argv[i][0] == '-' && argv[i][2] == 'x') ||
            (argv[i][0] == '-' && argv[i][3] == 'x') || (argv[i][0] == '-' && argv[i][4] == 'x') ||
            (argv[i][0] == '-' && argv[i][5] == 'x'))
        {

            chiBool = 1;
        }

        if ((strcmp(argv[i], "-n") == 0 && argv[i][2] == '\0') ||
            (argv[i][0] == '-' && argv[i][1] == 'n') || (argv[i][0] == '-' && argv[i][2] == 'n') ||
            (argv[i][0] == '-' && argv[i][3] == 'n') || (argv[i][0] == '-' && argv[i][4] == 'n') ||
            (argv[i][0] == '-' && argv[i][5] == 'n'))
        {
            suppress = 1;
        }

    } /*Finished checking for args*/

    /*Error arguments for the arguments*/
    if ((suppress == 1 && outputBool == 1) ||
        (strcmp(inputFile[0], outputFile[0]) == 0))
    {
        fprintf(stderr, "%s\n", "Error");
    }

    if (outputBool == 1 && suppress == 1)
    {
        suppress = 0; /*Disable the supress*/
    }

    /*Open the file if we have an input file*/
    if (inputBool == 1)
    {
        /*Open the file only if we have an input file*/
        fp = fopen(inputFile[0], "r");

        /*Malloc for the file size here*/
        size = file_size(fp);
        string = malloc(sizeof(char) * size);

        if (fp == NULL)
        {
            printf("This file doesn't exist\n");
            exit(1);
        }
    }
    else
    {

        fp = stdin; /*The input will be from stdin*/
    }

    if (inputBool == 0)
    {
        /*Malloc for the max length of the string first*/
        string = malloc(sizeof(char) * MAXLENGTH);
        currentSize = MAXLENGTH;
    }
    /*We will always have stdin or input file*/
    /*Now we want to construct the string from the file*/
    while ((c = fgetc(fp)) != EOF)
    {

        totalCharacters++;
        string[arrayCount] = c; /*Create the string for now*/
        arrayCount++;

        if ((arrayCount == currentSize) && (inputBool == 0))
        {
            currentSize += arrayCount + MAXLENGTH;
            string = realloc(string, currentSize);
        }
    }
    string[arrayCount] = '\0';

    text_freq = create_freq_table();
    add_letters(text_freq, string);

    if (inputBool == 1)
    {
        fclose(fp);
    }
    fp = NULL;

    /*Dont print in this iteration*/
    if (chiBool == 1)
    {
        shift = encode_shift(string, text_freq, tempBool); /*Gives us value which will encode the text*/
    }
    else
    {
        shift = encode_shift(string, text_freq, chiBool);
    }
    decode_value = to_decode(shift); /*Value which will decode the text*/

    /*Print out the s flags before anything else*/
    if (sbool == 1)
    {
        printf("value for decoding the message : %d\n", decode_value);
        printf("\n");
    }
    if (Sbool == 1)
    {
        printf("value for encoding the message: %d\n", shift);
        printf("\n");
    }

    /*print out the chi information*/
    if (chiBool == 1)
    {
        /*We can compute chi_squared and print it out*/
        shift = encode_shift(string, text_freq, chiBool);
        printf("\n");
    }

    if (freqBool == 1)
    {

        /*Print out the frequency table*/
        printf("c => text_freq");
        printf("\n");

        for (i = 0; i < 26; i++)
        {
            printf("'%c' =>  %d\n", i + 97, text_freq[i]);
        }
        printf("\n");
    }

    /*Make sure the output is not suppressed*/
    if ((suppress == 0) && (inputBool == 1))
    {

        /*Open the file only if we have an input file*/
        fp0 = fopen(inputFile[0], "r");

        if (fp0 == NULL)
        {
            printf("This file doesn't exist\n");
            exit(1);
        }
    }

    if ((suppress == 0) && (outputBool == 1))
    {

        /*Will either go to the file or stddout, only if there is no n*/
        /*Open the output file if we have the output file*/

        /*Open the file only if we have an input file*/
        fp2 = fopen(outputFile[0], "w");

        if (fp2 == NULL)
        {
            printf("This file doesn't exist\n");
            exit(1);
        }
    }

    /*fp2 is the output file and fp0 is the inputfile*/
    if (suppress == 0 && outputBool == 1 && inputBool == 1)
    {

        while ((x = fgetc(fp0)) != EOF)
        {

            if (sbool == 1)
            {

                shiftedChar = encode(x, decode_value); /*Pass in value to decode the text*/
                fputc(shiftedChar, fp2);               /*To the stdout or to the file*/
            }
            else if (Sbool == 1)
            {
                shiftedChar = encode(x, decode_value); /*Pass in value to encode the text*/
                fputc(shiftedChar, fp2);               /*To the stdout or to the file*/
            }
            else
            {

                fputc(x, fp2); /*Print everything normally from file to file otherwise*/
            }
        }
        printf("\n");

        /*Closing each of the files*/
        fclose(fp0);
        fp0 = NULL;

        fclose(fp2);
        fp2 = NULL;
    }
    /*Print to stdout through only the string**/
    else if ((suppress == 0) && (outputBool == 0)) /*Dont need to worry about file here*/
    {
        for (i = 0; string[i] != '\0'; i++)
        {

            /*Encode or decode the string and print to stdout*/
            if (sbool == 1)
            {

                shiftedChar = encode(string[i], decode_value); /*Pass in value to decode the text*/
                fprintf(stdout, "%c", shiftedChar);            /*To the stdout or to the file*/
            }
            else if (Sbool == 1)
            {
                shiftedChar = encode(string[i], decode_value);
                fprintf(stdout, "%c", shiftedChar);
            }
            else
            {
                fprintf(stdout, "%c", string[i]);
            }
        }
        printf("\n");
    }

    /*Remember to free malloc'ed memory*/
    free(string);
    string = NULL;

    free(text_freq);
    text_freq = NULL;

    return 0;
}
