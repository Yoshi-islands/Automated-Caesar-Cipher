#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"

/*This function will provide the offset for the letter for the EF array*/
int offset(char c)
{

    int offsetNum = 0;

    if ((c > 64 && c < 91)) /*Indicates the range for capitals and lowercases*/
    {

        offsetNum = c - 65; /*This will give us the difference from A*/
    }
    else if ((c > 96 && c < 123))
    {

        /*Management of the lowercase letters*/
        offsetNum = c - 97;
    }

    return offsetNum;
}
