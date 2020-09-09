#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"

/*This funtion returns the minimum chi_sq shift which was found in chi_sqaured function*/
int encode_shift(char *string, int *text_freq, int chiBool)
{

    int n = 0;
    int i = 0;
    double temp = 1000.0;
    double sumTotal = 0.0;
    int shift = 0;

    n = letter_count(string); /*Only need to count the letters once*/

    /*Print for boolean*/
    if (chiBool == 1)
    {
        printf("shift => chi_square(shift)\n");
    }

    /*Using a for loop check for the smallest chi_value, for each shift*/
    for (i = 0; i < 26; i++)
    {

        sumTotal = chi_sq(i, n, text_freq);

        if (chiBool == 1)
        {
            printf("%d => %f\n", i, sumTotal);
        }

        /*Temp is the last chi sum from the last shift*/
        if (sumTotal < temp)
        {
            shift = i;
            temp = sumTotal; /*Compares the next total chi*/
        }
    }

    /*Assume that the text is not english*/
    if ((temp >= 0.5) && (n < 200)) /*Text must be large enough for this to hold*/
    {
        shift = 0;
    }

    return shift;
}