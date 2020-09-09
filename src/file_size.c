#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions_q2.h"
#include "functions_q1.h"

int file_size(FILE *fp)
{
    int sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);

    return sz;
}
