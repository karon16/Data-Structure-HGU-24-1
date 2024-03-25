#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#define FILE_NAME "file.txt"

int main(void) {
    // create an array to hold letters and numbers letters from [0,25] and numvers from [26,35] and fill with zeros
    int characters[35] = {0};

    //read the file
    FILE *file = NULL;
    file = fopen(FILE_NAME, "r");

    //check for errors while opening the file
    if(file == NULL){
        printf("[Error] : Failed to open file %s\n", FILE_NAME);
        return -1;
    }

    // if the file opened successfully read every character
    int c=0;
    while(((c = fgetc(file)) != EOF)){
        // check it the lowercase character is a alpha character and increment by one characters[c-97]
        // 97 represents the ASCII value of "a" 
        if(isalpha(tolower(c)) != 0){
            characters[c - 97] += 1;
        //check if the character is a digit and increment by one character[(c-48) + 26] 
        // 48 represents the ASCII value "0"
        }else if(isdigit(c) != 0){
            characters[(c - 48) + 26] += 1;
        }
        
    }

    for(int i = 0; i < 35; i++){
        if(i < 26){
            printf("%c: %d\n",toupper(i + 97) , characters[i]);
        }else{
            printf("%c: %d\n",((i - 26) + 48) , characters[i]);
        }
    }


    return 0;
}