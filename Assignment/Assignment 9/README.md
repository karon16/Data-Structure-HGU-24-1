# Text Reviser

This program revises a text file based on a given map file and prints the revised text.

## User Input

The program requires two input files:
1. **Text File**: This file contains the text to be revised.
2. **Map File**: This file specifies the mapping of source words to target words.

## Output

The revised text is printed on the screen.

## Map File Format

Each line in the map file follows this format:

```
SOURCE_WORD: TARGET_WORD
```

- `SOURCE_WORD`: The word in the text to be replaced.
- `TARGET_WORD`: The word that replaces `SOURCE_WORD`.

## Binary Search Tree

The program builds a binary search tree using the map file. It uses the source word as the key and the target word as the data.

## Case and Punctuation

The program does not ignore case or punctuation marks. It performs replacements as specified in the map file.

## Example

### Input Files

**Text File:**
```
Barack Hussein Obama is an American politician who is the 44th
and current President of the united States.
```

**Map File:**
```
Hussein: H.
current: previous
united: United
```

### Output

```
Barack H. Obama is an American politician who is the 44th
and previous President of the United States.
```

This output is based on the replacements specified in the map file.

## How to Run

1. Provide the text file and the map file as input.
2. Run the program.
3. The revised text will be printed on the screen.

