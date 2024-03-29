#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float** transpose_matrix(float** a, int ah, int aw);

// Function prototypes (declarations) for clarity
float **make2dArray(int rows, int cols);
void free2dArray(float** array, int rows);
void readFile(float** a, const char* file_name); // Use const char* for safer string handling

int main(void) {
    char operation[1];
    char file_a_name[10], file_b_name[10];
    int ah, aw, bh, bw;
    int i, j, k;

    float** a = NULL;
    float** b = NULL;

    printf("> What operation do you want? ('a', 'm', 't') -> ");
    scanf("%c", operation);

    if (strcmp(operation, "a") == 0) {
        printf("> Input first file name -> ");
        scanf("%s", file_a_name);
        printf("> Input second file name -> ");
        scanf("%s", file_b_name);

        // open files
        FILE *file_a = NULL;
        FILE *file_b = NULL;
        file_a = fopen(file_a_name, "r");
        file_b = fopen(file_b_name, "r");

        // check for errors file opening files
        if (file_a == NULL || file_b == NULL) {
            printf("> Error opening files.\n");
            return 1; // Indicate error
        }

        // get rows and colums for each matrix
        fscanf(file_a, "%d %d", &ah, &aw);
        fscanf(file_b, "%d %d", &bh, &bw);

        // check for matrix missmatch errors
        if (aw != bw || ah != bh) {
            printf("Matrix dimensions mismatch\n");
            fclose(file_a);
            fclose(file_b);
            return 1; // Indicate error
        }

        //if no error, allocate memory for each matrix
        a = make2dArray(ah, aw);
        b = make2dArray(bh, bw);

        // fill each cell of the each matrix
        for (i = 0; i < ah; i++) {
            for (j = 0; j < aw; j++) {
                fscanf(file_a, "%f", &a[i][j]);
                fscanf(file_b, "%f", &b[i][j]);
            }
        }

        // close file after reading all data
        fclose(file_a);
        fclose(file_b);

        //perform addition
        float **result = NULL; 
        result = make2dArray(ah, aw); // allocate memory for result array

        for (i = 0; i < ah; i++) {
            for (j = 0; j < aw; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
        
        //print result
        printf("%-3d%d\n", ah, aw);
        for (i = 0; i < ah; i++) {
            for (j = 0; j < aw; j++) {
                printf("%-3.f", result[i][j]);
            }
            printf("\n");
        }

        // free memory
        free2dArray(a, aw);
        free2dArray(b, bw);

    } else if (strcmp(operation, "m") == 0) {
        // get file names
        printf("> Input first file name -> ");
        scanf("%s", file_a_name);
        printf("> Input second file name -> ");
        scanf("%s", file_b_name);

        // open and read files
        FILE *file_a = NULL;
        FILE *file_b = NULL;
        file_a = fopen(file_a_name, "r");
        file_b = fopen(file_b_name, "r");

        // check for errors file opening files
        if (file_a == NULL || file_b == NULL) {
            printf("> Error opening files.\n");
            return 1; // Indicate error
        }

        // get rows and colums for each matrix
        fscanf(file_a, "%d %d", &ah, &aw);
        fscanf(file_b, "%d %d", &bh, &bw);

        // check for matrix missmatch errors
        if (aw != bh) {
            printf("Matrix dimensions mismatch\n");
            fclose(file_a);
            fclose(file_b);
            return 1; // Indicate error
        }

        //if no error, allocate memory for each matrix
        a = make2dArray(ah, aw);
        b = make2dArray(bh, bw);

        // populate matrix a with data
        for (i = 0; i < ah; i++) {
            for (j = 0; j < aw; j++) {
                fscanf(file_a, "%f", &a[i][j]);
            }
        }

        // populate matrix b with data
        for (i = 0; i < bh; i++) {
            for (j = 0; j < bw; j++) {
                fscanf(file_b, "%f", &b[i][j]);
            }
        }

        // close file after reading all data
        fclose(file_a);
        fclose(file_b);

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

         //print result
        printf("%-5d%d\n", aw, bh);
        for (i = 0; i < ah; i++) {
            for (j = 0; j < bw; j++) {
                printf("%-5.f", result[i][j]);
            }
            printf("\n");
        }

        // free memory
        free2dArray(a, aw);
        free2dArray(b, bw);

    } else if (strcmp(operation, "t") == 0) {
        // get file name
        printf("> Input file name -> ");
        scanf("%s", file_a_name);

        //open and read file
        FILE *file_a = NULL;
        file_a = fopen(file_a_name, "r");

        // check for errors file opening files
        if (file_a == NULL) {
            printf("> Error opening file.\n");
            return 1; // Indicate error
        }

        // get rows and colums for each matrix
        fscanf(file_a, "%d %d", &ah, &aw);

        // Allocate memory for each matrix
        a = make2dArray(ah, aw);

        // populate matrix a with data
        for (i = 0; i < ah; i++) {
            for (j = 0; j < aw; j++) {
                fscanf(file_a, "%f", &a[i][j]);
            }
        }

         // close file after reading all data
        fclose(file_a);

        //perform transposition transformation
        float **result = NULL; 
        result = make2dArray(aw, ah); // allocate memory for result array
        
        for (i = 0; i < aw; i++) {
            for (j = 0; j < ah; j++) {
                result[i][j] = a[j][i];
            }
        }

        // print result
        printf("%-2d%d\n", ah, aw);
        for (i = 0; i < aw; i++) {
            for (j = 0; j < ah; j++) {
                printf("%-2.f",result[i][j]);
            }
            printf("\n");
        }

        // free memory
        free2dArray(a, aw);
        free2dArray(b, bw);
        
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