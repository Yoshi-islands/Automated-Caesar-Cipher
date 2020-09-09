#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q1.h"

/*This function will open the file and construct the string*/ 
char * file_string ( char * inputFile )
{ 

        char * string; 
        FILE *fp;
        int size = 45; /*This is for the max file size so that we can malloc*/ 
        
       
        fp = fopen(inputFile,"r");
        

        if ( fp == NULL)
        {
                printf("This file doesn't exist\n");
                exit (1);
        }

        int arrayCount = 0; 
        char c; 

        /*Malloc for the string*/ 
        string = malloc ( sizeof (char)*45); 

        /*Now we want to construct the string from the file*/ 
        while (( c = fgetc (fp)) != EOF) 
        {   
            if ( c != '\n' || c!= ' ')
            {
                    
            }

            if ( (c > 63 && c < 123) || (c == '\n') || ( c == '\0'))
            {
                string[arrayCount] = c; 
                arrayCount++; 
            }

        }

         printf("%s\n", string);

    fclose(fp);

    return string; 
}