# File Content Reversal and Stack Implementation in C++

This C++ assignment involves reading a file and printing its lines in reverse order. Additionally, you are tasked with implementing a stack using a linked list.

## File Format

- Each line of the input file should be in the following format:
  ```
  name, id, email
  ```
- Elements are separated by commas, representing a record with name, id, and email.

## Output

- The program will print each line of the input file in reverse order, with the elements rearranged in the following format:
  ```
  id, name, email
  ```

## Example

### Input File (`input.txt`):

```
Geoffrey, 17, hinton@handong.edu
Yoshua, 12, yoshua@handong.edu
Yann, 13, yann@handong.edu
Cho, 55, cho@handong.edu
Alex, 57, alex@handong.edu
```

### Output:

```
57, Alex, alex@handong.edu
55, Cho, cho@handong.edu
13, Yann, yann@handong.edu
12, Yoshua, yoshua@handong.edu
17, Geoffrey, hinton@handong.edu
```

## Note

Ensure the input file is present in the same directory as the compiled program, or provide the full path to the file when prompted.