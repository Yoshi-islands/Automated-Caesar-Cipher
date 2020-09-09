#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"

/*This function will shift the character*/
int encode(char c, int shift)
{

        char m;
        /*Look at the ascii range for letters*/
        if ((c > 96 && c < 123))
        {
                if ((c + shift) < 123) /*shifting without wrapping around*/
                {
                        m = c + shift;
                }
                else /*Shifting with wrapping around*/
                {

                        m = (c - 26) + shift;
                }
        }
        else if ((c > 64 && c < 91)) /*For the capital letters*/
        {
                if ((c + shift) < 91) /*shifting without wrapping around*/
                {
                        m = c + shift;
                }
                else
                {
                        m = (c - 26) + shift;
                }
        }
        else
        {
                m = c;
        }

        return m;
}
