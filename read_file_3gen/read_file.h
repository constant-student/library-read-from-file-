#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern int amount_strings;
extern int amount_columns;



double** read(FILE* text);

double** reverse(double** strings, int N_strings=amount_strings, int N_columns=amount_columns);

int show_matrix(double** text, int N_strings=amount_strings, int N_columns=amount_columns);