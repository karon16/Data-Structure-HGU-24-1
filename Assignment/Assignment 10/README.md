# Word Frequency Counter

Given a text file, this program finds the 5 most frequent words and their frequency.

## User Input
The user should provide the file name of a text file (e.g., 'input1.txt' or 'input2.txt').

## Process
1. **Read the Text File**: Read all the lines from the text file.
2. **Parse Lines into Words**:
   - Use whitespace as a delimiter to parse each line into words.
   - Before parsing, replace punctuations with whitespace.
   - Consider only alphanumeric characters.
3. **Count Word Frequencies**: Count the frequency of the words, ignoring case.
4. **Sort Words**:
   - Sort the words by their frequency.
   - Select a sorting algorithm from the provided slide and implement it (include a comment on why the algorithm was selected).
   - If words have the same frequency, sort them by alphabetical order.
5. **Print the Top 5 Words**: Print the 5 most frequent words with their frequency in uppercase.

## Assumptions
- The maximum number of unique words is 2048 (i.e., the cardinality of the unique word set is at most 2048).

## Example
Given a text file with the following content:

```
In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification [1][2][3]. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data [4].
```

The output on the screen should be:

```
DATA: 5
A: 4
AND: 3
THE: 3
IS: 2
```