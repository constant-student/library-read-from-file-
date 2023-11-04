#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern int amount_strings;
extern int amount_columns;



int N_string(FILE* text);

double** read(FILE* text);

double** build_columns(double** strings);