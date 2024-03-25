## README.md

This program implements basic matrix operations: addition (`+`), multiplication (`x`), and transpose (`transpose`). Each operation is defined as a separate function.

**Dependencies:**

* `make2dArray`: Function to allocate memory for a 2D array.
* `free2dArray`: Function to free memory allocated for a 2D array. (Implementations not provided)


**Functions:**

* `float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw)`: Adds two matrices `a` and `b`.
* `float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw)`: Multiplies two matrices `a` and `b`.
* `float** transpose_matrix(float** a, int ah, int aw)`: Transposes matrix `a`.

**Output:**

1. **"Matrix dimensions mismatch"**: When matrix dimensions for an operation are incompatible (e.g., 3x4 and 5x6).
2. **Output matrix dimensions and elements**: Prints the size (rows x columns) followed by elements of the resulting matrix.

**Example Output:**

```
The output is:

3 3

1 2 3

4 5 6

7 8 9
```

**Steps:**

1. **Read operation character**: Prompts for an operation character (`a` for addition, `m` for multiplication, `t` for transpose).
2. **Read input files**: Based on the chosen operation, reads one or two files containing matrix data. Each file starts with the matrix size (rows x columns) followed by the matrix elements.
3. **Check matrix sizes**: Verifies compatibility of matrix dimensions for the chosen operation.
4. **Print output matrix**: If dimensions are compatible, prints the size and elements of the resulting matrix following the same format as the input.

**Example 1:**

```
% a.out

What operation do you want? (‘a’, ‘m’, ‘t’)

a

Input files names:

a.txt
b.txt

The output is

2 3

5.2 1.7 3.1

1.1 9.4 2.8
```

**Example 2:**

```
% a.out

What operation do you want? (‘a’, ‘m’, ‘t’)

a

Input files names:

a.txt
c.txt

The output is

Matrix dimensions mismatch
```
