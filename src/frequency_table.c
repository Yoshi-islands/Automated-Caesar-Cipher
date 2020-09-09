#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q1.h"
/*
 *   Program name: frequency_table
 *   Author: Maaz Syed
 *   Last Update: March 9th, 2020
 *   Function: This is the main for all the function in the first part
 *   Compilation: make file
 *   Execution: make file
 */

int main(int argc, char *argv[])
{

    char inputFile[20][20];
    int i = 0;
    int length = 0;
    int j = 0;
    int count = 0;
    int size = 0;
    int inputBool = 0;
    char *string;
    FILE *fp;
    int arrayCount = 0;
    char c;
    int totalCharacters = 0;
    int letterCount = 0;
    int *freq_table;
    int currentSize = 0;

    /*We first want to search if there is command line flags*/
    /*We need to check for the existence of each of the command lines*/
    for (i = 0; i < argc; i++)
    {

        /*This is the case where there is no space after -F flag*/
        if ((argv[i][0] == '-') && (argv[i][1] == 'F') && (argv[i][2] != '\0'))
        {
            inputBool = 1; /*True*/
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
        }

        /*This is the case that there is a space after the -F*/
        if ((strcmp(argv[i], "-F") == 0) && (argv[i][2] == '\0'))
        {
            inputBool = 1; /*True*/
            length = strlen(argv[i + 1]);
            /*put contents with a for loop into the array*/
            for (j = 0; j < length; j++)
            {
                inputFile[0][j] = argv[i + 1][j];
            }
            inputFile[0][j] = '\0';
        }
    }

    /*Based on the boolean operations we will perform some actions*/
    if (inputBool == 1)
    {
        fp = fopen(inputFile[0], "r");

        /*Malloc for the size of the file here*/
        size = file_size(fp);
        string = malloc(sizeof(char) * size);

        if (fp == NULL)
        {
            printf("This file doesn't exist\n");
            exit(1);
        }

        /*Now we want to construct the string from the file*/
        while ((c = fgetc(fp)) != EOF)
        {

            totalCharacters++;

            if ((c > 64 && c < 91) || (c > 96 && c < 123)) /*Only adding to the string if its a letter*/
            {
                string[arrayCount] = c;
                arrayCount++;
            }
        }
        string[arrayCount] = '\0';

        fclose(fp);

        /*Print the correct information*/
        letterCount = letter_count(string);
        printf("the number of letters in the text: %d\n", letterCount);
        printf("the number of characters in the text: %d\n", totalCharacters);

        printf("\n");

        /*Print out the correct columns*/
        printf("Letters:\t");
        printf("Letter frequency:\n");

        /*Create the frequency table*/
        freq_table = create_freq_table();

        /*Pass the string and table made*/
        add_letters(freq_table, string);

        /*Print out the whole table now*/
        for (i = 0; i < 25; i++)
        {

            printf("%c\t\t%d\n", i + 65, freq_table[i]); /*Displaying information with tabs as described*/
        }
    }
    else if (inputBool == 0)
    {

        string = malloc(sizeof(char) * MAXLENGTH);

        /*We then want to do things based on stdin*/
        while ((c = fgetc(stdin)) != EOF)
        {

            totalCharacters++; /*This is to count all of the characters*/

            if ((c > 64 && c < 91) || (c > 96 && c < 123))
            {
                string[arrayCount] = c;
                arrayCount++;
            }

            if ((arrayCount == currentSize))
            {
                currentSize += arrayCount + MAXLENGTH;
                string = realloc(string, currentSize);
            }
        }
        string[arrayCount] = '\0';
        letterCount = letter_count(string);
        printf("the number of letters in the text: %d\n", letterCount);
        printf("the number of characters in the text: %d\n", totalCharacters);
        printf("\n");

        /*Print out the correct columns*/
        printf("Letters:\t");
        printf("Letter frequency:\n");

        /*Create the frequency table*/
        freq_table = create_freq_table();

        /*Pass the string and table made*/
        add_letters(freq_table, string);

        /*Print out the whole table now*/
        for (i = 0; i < 25; i++)
        {

            printf("%c\t\t%d\n", i + 65, freq_table[i]); /*Displaying information with tabs as described*/
        }
    }

    /*Make sure all the information is freed*/
    free(string);
    string = NULL;

    free(freq_table);
    freq_table = NULL;

    return (0);
}