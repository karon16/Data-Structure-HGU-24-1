
# 1. Tokenization process (Elements here are operators)
 Compare the current operator with the previous one in the stack
if the current operator is less the previous, we pop the previous and push the current 

### No paranthesis

* a*b+c => a 
* a*b+c => Stack.push *
* a*b+c => b => ab
* a*b+c => Stack.pop *, because + is less than *, => ab*
* a*b+c => Stack.push(+)
* a*b+c => c => ab*c
* a*b+c => Stack.pop(+) => ab*c+ after reaching end of sentence

### in case of paranthesis
Parentheis represent a sub operation
* a * (b+c)/d

*a * (b+c)/d => a
* a * (b+c)/d => Stack.push(*) => *
* a * (b+c)/d => Stack.push(opening parenthesis) => *(
* a * (b+c)/d => b => ab
* a * (b+c)/d => Stack.push(+) => *(+
* a * (b+c)/d => c => abc
* a * (b+c)/d => encounter the closing parentheis, so => Stack.pop(+) => Stack.pop(opening parenthesis) => *, a * (b+c)/d => abc+
* a * (b+c)/d => first compare operators (* is similar to /, however * came first) so we first po => Stack.pop(*) => a * (b+c)/d => abc+* => Stack.push(/)
* a * (b+c)/d => d => a * (b+c)/d => abc+*d
* a * (b+c)/d => end of line

# 2. Evaluation process (Elements are numbers)

* only two operands at a time
* push the numbers to the until you encounter
* pop both operands after encounter an operator and push the result


