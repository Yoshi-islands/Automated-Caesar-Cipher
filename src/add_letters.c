#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q1.h"

/*In this function we will populate the array with the counts from the string*/
void add_letters(int *freq_table, char *string)
{
    int i = 0;
    int array_index = 0;

    /*Go through the entire array with while loop*/
    while ( string[i]!= '\0')
    {
        if (string[i] >= 'a' && string[i] <= 'z') /*Do for both lowercase and uppercase letters*/
        {

            array_index = string[i] - 'a';  /*will give us the index to store count into*/ 
            freq_table[array_index]++; 
        }
        else if ( string[i] >= 'A' && string[i] <= 'Z' )
        {
            array_index = string[i] - 'A'; 
            freq_table[array_index]++; 
        }

        i++;
    }

    return;
}