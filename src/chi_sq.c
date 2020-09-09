#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"

/*This function is the chi_squared which calculates the formula*/
/*Assumes we are allowed to have more parameters as directed*/

double chi_sq(int shift, int n, int *text_freq)
{

    /*Variables*/
    int i = 0;
    double EF[26] = ef; /*Array from the function definitions*/
    double chi_stat = 0.0;
    char c;
    double sumTotal = 0.0;

    for (i = 0; i < 26; i++)
    {
        /*For each character*/
        c = i + 97;

        chi_stat = ((n * EF[offset(c)] - text_freq[offset(encode(c, shift))]) * (n * EF[offset(c)] - text_freq[offset(encode(c, shift))])) / (n * n * EF[offset(c)]);
        sumTotal += chi_stat;
    }

    return sumTotal; /*Total of the summation at that specific shift*/
}