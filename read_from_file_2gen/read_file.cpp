#include "read_file.h"

int amount_strings;
int amount_columns=-1;

int N_string(FILE* text) //counting of amount of strings
{
    fseek(text,0,SEEK_SET);
    int i=0;
    char a;
    bool flag_no_empty=0; //check of empty string
    if(text==NULL) printf("error\n");
    else while( (a=fgetc(text))!= EOF) 
    {
        if(a!=' ' && a!='\n' && flag_no_empty==0) {flag_no_empty=1;}
        if(a=='\n' && flag_no_empty==1) {i++;flag_no_empty=0;}
    }
    fseek(text,0,SEEK_SET);
    amount_strings=i;
    return i;
}




double** read(FILE* text)// reading of data from file
{
    char a;
    int length=N_string(text);
    if (length==0) return (double**)1;
    double** strings=(double**)malloc(sizeof(double*)*length);
 
    for(int i=0;i<length;i++)
    {
        int counter_word=1;
        int counter_bite=0;
        bool flag_gap=0;
        bool flag_no_empty=0;
        
        while((a=fgetc(text))!=EOF) 
            { 
                if(a==' ' && flag_gap==0) {flag_gap=1;} 
                if(a!=' ' && a!='\n' && flag_gap==1) {flag_gap=0; counter_word++;}
                if(a!=' ' && a!='\n') {flag_no_empty=1;}
                if(a=='\n') {break;} 
                counter_bite++;
            }
        if(counter_bite!=0)
        {

            if (amount_columns==-1) amount_columns=counter_word;
            if (counter_word<amount_columns) amount_columns=counter_word;

            double* words=(double*)malloc(sizeof(double)*counter_word);
            fseek(text,-(counter_bite+2),SEEK_CUR);
            for(int j=0;j<counter_word;j++)
            {
                fscanf(text,"%lf ",&(words[j]));
                printf("%lf ", words[j]);
            }
            printf("\n");
            strings[i]=words;
        }
        else i--; // because it was empty string
        
    }

    return strings;
}

double** build_columns(double** strings) //transverse strings to columns ( read() return strings)
{
    double** columns=(double**)malloc(amount_columns*sizeof(double*));
    for (int i=0;i<amount_columns;i++)
        {
            double* column=(double*)malloc(amount_strings*sizeof(double));
            for(int j=0;j<amount_strings;j++)
                column[j]=strings[j][i];
            columns[i]=column;
        }
    return columns;       
}