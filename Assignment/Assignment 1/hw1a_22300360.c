#include <stdio.h>
#include <stdlib.h>
#define FILE_BASE "./Test files/"

void sort(int list[], int len);
int getNumbersCount(char file_name[]);
int getSmallestNumber(char file_name[]);



int main(void){
    char file_names[3][25] = {"./Test files/file1.txt","./Test files/file2.txt","./Test files/file3.txt"};

    for(int i = 0; i < 3; i++){
        int smallest = getSmallestNumber(file_names[i]);
        printf("Input filename: %s\n", file_names[i]);
        printf("The smallest number is %d\n", smallest);
    }

    return 0;
}

int getSmallestNumber(char file_name[]){
    int *arr= NULL;
    
    FILE *file;
    file = fopen(file_name, "r");

    if(file == NULL){
        printf("Error: Cannot open file %s\n", file_name);
        return -1;
    }

    int count = getNumbersCount(file_name);
    arr = (int *)malloc(count*sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return -1;
    }

    for(int i=0; i<count; i++){
         if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading a number from the file!\n");
            fclose(file);
            free(arr);
            return 1;
        }
    }

    fclose(file);

    sort(arr, count);

    return arr[0];
}

int getNumbersCount(char file_name[]){
    FILE *file;
    file = fopen(file_name, "r");

    int i=0;
    while (!feof(file)) {
        int num;
        int size = fscanf(file, "%d", &num);
        if (size == 1)
            i++;
  }
  fclose(file);
  return i;
}


void sort(int list[], int len){
    int i, j, min, temp;
    for(i = 0; i < len - 1; i++){
        min = i;
        for(j = i + 1; j < len ; j++){
            if(list[min] > list[j]){
                min = j;
            }
        }
        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}
