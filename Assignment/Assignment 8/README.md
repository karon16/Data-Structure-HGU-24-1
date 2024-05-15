# Binary Search Tree System

Implement an interactive Binary Search Tree system as described below.

## Input Format

The format of each keyboard input line should be as follows:

```
command [key [value]]
```

- **command:** a character representing the action to be performed.
- **key:** an integer representing the key value.
- **value:** a string representing the associated value.

The commands include:
- **a:** add
- **d:** delete
- **p:** print (in inorder)
- **q:** quit the program

## Example Input

```
a 3 henry  ==> add (3, henry)
d 3         ==> delete key=3
```

## Example Execution

```bash
% run_bst
a 3 henry
a 2 choi
a 5 handong
a 2 global (print out “2 is already in the tree”)
a 9 university
d 3
d 7 (print out “7 is not in the tree”)
p (should print out the nodes (key, value))
d 5
p (should print out the nodes (key, value))
q
```

- Entering "p" (print) should print out the nodes using inorder traversal to print out the (key,value) pairs.
- Upon entering a duplicate key value, print out: "<the key> is already in the tree".
- Upon deletion, if the key is not in the BST, print the following error message: "<the key> is not in the tree".

You can reuse any code from our lecture slides.