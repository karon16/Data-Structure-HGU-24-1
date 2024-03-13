#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


#define FILE_NAME "./Test files/example1.txt"

enum {STRING ,INTEGER, SPECIAL};

int main(void)
{
    FILE *file;
    file = fopen(FILE_NAME, "r");
    char temp[32];
    int i, c, type;
    float number;
    float sum = 0.0;

    if(file == NULL){
        printf("Error: cannot open file '%s'\n", FILE_NAME);
        return -1;
    }

    while((c = fgetc(file)) != EOF){
        temp[i] = c;
        if(isdigit(c)){
            type = INTEGER;
            ++i;
        } else if(isspace(c) || c == ','){
            temp[i] = '\0';
           if(type == INTEGER){
                number = atof(temp);
                printf("%.2f\n", number);
                sum += number;
            }
            type = SPECIAL;
            i = 0;
        } else if(c == '.'){
            i++;
        }
        else {
            if(i < 1){
                type = STRING;
                i = 0;
            }
          
        }
    }

    printf("sum : %.2f\n", sum);
    return 0;
}
