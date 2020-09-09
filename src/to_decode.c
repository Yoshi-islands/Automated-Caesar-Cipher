#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"

/*This function will return us the decoding value*/
int to_decode(int shift)
{

    /*Take shift into a decoding value*/
    int decode_value = 0;
    decode_value = 26 - shift; /*For the number of alphabets there are*/

    if (shift == 0)
    {
        decode_value = 26;
    }

    return decode_value;
}
