#include <stdio.h>

void sort(int list[], int len);

int main(void){
    int aList[] = {0, 3, 1, 5, 7, 9, 2};
    sort(aList, 7);

    for(int i=0; i<7; i++)
        printf("%d ", aList[i]);

    return 0;
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
