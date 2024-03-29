#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// functions for matrix operations
float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float** transpose_matrix(float** a, int ah, int aw);

// utility functions
float **make2dArray(int rows, int cols);
void free2dArray(float** array, int rows);
int* read_file(float*** a, int* matrix_size); 

int main(void) {
    char operation[1];
    char file_a_name[10], file_b_name[10];
    int matrix_a_size[2], matrix_b_size[2];
    int ah, aw, bh, bw;
    int i, j, k;

    float** a = NULL;
    float** b = NULL;

    printf("> What operation do you want? ('a', 'm', 't') -> ");
    scanf("%c", operation);

    if (strcmp(operation, "a") == 0) {

        //call function read_file to read files
        read_file(&a, matrix_a_size);
        ah = matrix_a_size[0];
        aw = matrix_a_size[1];

        read_file(&b, matrix_b_size);
        bh = matrix_b_size[0];
        bw = matrix_b_size[1];

        // check for matrix missmatch errors
        if (aw != bw || ah != bh) {
            printf("Matrix dimensions mismatch\n");
            return 1; // Indicate error
        }

        float **result = add_matrix(a, ah, aw, b, bh, bw);

        //print result
        printf("%-3d%d\n", ah, aw);
        for (i = 0; i < ah; i++) {
            for (j = 0; j < aw; j++) {
                printf("%-3.f", result[i][j]);
            }
            printf("\n");
        }

    } else if (strcmp(operation, "m") == 0) {
        //call function read_file to read files
        read_file(&a, matrix_a_size);
        ah = matrix_a_size[0];
        aw = matrix_a_size[1];

        read_file(&b, matrix_b_size);
        bh = matrix_b_size[0];
        bw = matrix_b_size[1];

        // check for matrix missmatch errors
        if (aw != bh) {
            printf("Matrix dimensions mismatch\n");
            return 1; // Indicate error
        }

        float **result = mul_matrix(a, ah, aw, b, bh, bw);

        //print result
        printf("%-5d%d\n", aw, bh);
        for (i = 0; i < ah; i++) {
            for (j = 0; j < bw; j++) {
                printf("%-5.f", result[i][j]);
            }
            printf("\n");
        }

    } else if (strcmp(operation, "t") == 0) {
        //call function read_file to read files
        read_file(&a, matrix_a_size);
        ah = matrix_a_size[0];
        aw = matrix_a_size[1];

        float **result = transpose_matrix(a, ah, aw);

        // print result
        printf("%-2d%d\n", ah, aw);
        for (i = 0; i < aw; i++) {
            for (j = 0; j < ah; j++) {
                printf("%-2.f",result[i][j]);
            }
            printf("\n");
        }
 
    } else {
        printf("Invalid operation.\n");
    }
    return 0;
}


float ** make2dArray(int rows, int cols){ /* create a two dimensional rows Í cols array */
    float **x = NULL;
    int i = 0;
    x = malloc(rows * sizeof (*x)); /* get memory for row pointers */
    for (i = 0; i < rows; i++) /* get memory for each row */
        x[i] = malloc(cols * sizeof(**x));
    return x;
}

void free2dArray(float **array, int rows){ // deallocates a two dimensional array
    int i = 0;
    for (i = 0; i < rows; i++) /* free memory for each row */
        free(array[i]);
    free(array); /* free memory for row pointers */
    return;
}

float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw){
    int i, j, k;
    //perform addition
    float **result = NULL; 
    result = make2dArray(ah, aw); // allocate memory for result array

    printf("inside add_matrix");

    for (i = 0; i < ah; i++) {
        for (j = 0; j < aw; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    // free memory
    free2dArray(a, aw);
    free2dArray(b, bw);

    // return result
    return result;
}

float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw){
    int i, j, k;
    // perform multiplication
    float **result = NULL; 
    result = make2dArray(ah, bw); // allocate memory for result array

    for (i = 0; i < ah; i++) {
        for (j = 0; j < bw; j++) {
            for(k = 0; k < aw; k++) {
                result[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    // free memory
    free2dArray(a, aw);
    free2dArray(b, bw);

    //return result
    return result;
}

float** transpose_matrix(float** a, int ah, int aw){ 
    int i, j, k;
    //perform transposition transformation
    float **result = NULL; 
    result = make2dArray(aw, ah); // allocate memory for result array

    for (i = 0; i < aw; i++) {
        for (j = 0; j < ah; j++) {
            result[i][j] = a[j][i];
        }
    }

    // free memory
    free2dArray(a, aw);

    // return result
    return result;
}

int* read_file(float*** a, int* matrix_size){
    int i, j, k;
    char file_name[10];
    int ah, aw;
    printf("> Input file name -> ");
    scanf("%s", file_name);

    // open files
    FILE *file = NULL;
    file = fopen(file_name, "r");

    // check for errors file opening files
    if (file == NULL) {
        printf("> Error opening files.\n");
        return NULL; // Indicate error
    }

    // get rows and colums for each matrix
    fscanf(file, "%d %d", &ah, &aw);

    //if no error, allocate memory for each matrix
    *a = make2dArray(ah, aw);

    // fill each cell of the each matrix
    for (i = 0; i < ah; i++) {
        for (j = 0; j < aw; j++) {
            fscanf(file, "%f", &((*a)[i][j]));
        }
    }

    matrix_size[0] = ah;
    matrix_size[1] = aw;

    // close file after reading all data
    fclose(file);

    // return the matrix size
    return matrix_size;
}
