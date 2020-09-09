#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "functions_q1.h"

/*Function that returns the number of characters within the string*/
int letter_count(char *line)
{

    int i = 0;
    int letterCount = 0;

    /*Loop that goes through the whole string*/
    while (line[i] != '\0')
    {
        /*Make sure the character is indeed an alphabet*/
        if (isalpha(line[i]) != 0)
        {
            /*Counts the ascii characters within the assumed range*/
            if ((line[i] > 64 && line[i] < 91) || (line[i] > 96 && line[i] < 123))
            {
                letterCount++;
            }
        }
        i++;
    }

    return letterCount;
}
