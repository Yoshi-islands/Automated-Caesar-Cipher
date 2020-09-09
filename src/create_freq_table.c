#include <stdlib.h>
#include <stdio.h>
#include "functions_q1.h"

/*In this function we will create the frequency table and return it empty*/
int *create_freq_table()
{
    int i = 0;
    int *freq_table;
    freq_table = malloc(sizeof(int) * 26);

    /*Initialize the array with 0's*/
    for (i = 0; i < 26; i++)
    {
        freq_table[i] = 0;
    }

    return freq_table;
}
