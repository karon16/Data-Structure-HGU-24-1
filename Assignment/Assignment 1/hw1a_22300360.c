//22300360 - Buhendwa Christopher Lulando

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// functions declaration
void sort(int list[], int len);
int getNumbersCount(char file_name[]);
int getSmallestNumber(char file_name[]);

int main(void){
    // get file name as an input from the user
    char file_name[10];
    printf("Input filename: ");
    scanf("%s",file_name);

    // get the smallest number by calling getSmallestNumber()
    int smallest = getSmallestNumber(file_name);
    // print the smallest number
    printf("The smallest number is %d\n", smallest);


    return 0;
}

// function to return the smallest number
int getSmallestNumber(char file_name[]){
    int *arr= NULL;
    int small_number;
    
    FILE *file;
    file = fopen(file_name, "r");

    // print error if there's a problem with the file
    if(file == NULL){
        printf("Error: Cannot open file %s\n", file_name);
        return -1;
    }

    // get the count of numbers by calling getNumbersCount()
    int count = getNumbersCount(file_name);
    //allocate memory for the arry with the count of numbers
    arr = (int *)malloc(count*sizeof(int));

    // print error if the memory allocation failed
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return -1;
    }

    // Populate the array with numbers from the file
    for(int i=0; i<count; i++){
        // if an error occur while reading the file, print error and close file
         if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading a number from the file!\n");
            fclose(file);
            free(arr);
            return 1;
        }
    }

    sort(arr, count);

    //assign the first element of the array to smallest_number
    small_number = arr[0];

    //free memory and close file
    free(arr);
    fclose(file);

    return small_number;
}

// get the number of lign in the file
int getNumbersCount(char file_name[]){
    //open file
    FILE *file;
    file = fopen(file_name, "r");
    
    int i=0;
    // loop through the file to get the count of numbers
    while (!feof(file)) {
        int num;
        int size = fscanf(file, "%d", &num);
        // increment if a number is found
        if (size == 1)
            i++;
  }
  fclose(file);
  return i;
}

// function to sort the list
void sort(int list[], int len){
    int i, j, min, temp;
    for(i = 0; i < len - 1; i++){
        min = i;
        for(j = i + 1; j < len ; j++){
            if(list[min] > list[j]){
                min = j;
            }
        }
        // swap indexes
        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}
