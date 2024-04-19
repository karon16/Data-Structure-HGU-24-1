#include <string.h>
#include "calc.h"
#include "stack.h"

Calculator::Calculator(string str) {
    postfix = infixToPostfix(str);
}

string Calculator::infixToPostfix(string infix) {
    string postfix;
    Stack<char> stack;

    for (size_t i = 0; i < infix.length(); ++i) {
        char token = infix[i];
        if (isdigit(token)) {
            postfix += token;
            postfix += ' '; // Add space to separate operands
        } else if (token == '(') {
            stack.push(token);
        } else if (token == ')') {
            while (!stack.isEmpty() && stack.read_top() != '(') {
                postfix += stack.pop();
                postfix += ' '; // Add space to separate operators
            }
            stack.pop(); // Discard the '('
        } else if (token == '+' || token == '-') {
            while (!stack.isEmpty() && stack.read_top() != '(') {
                postfix += stack.pop();
                postfix += ' '; // Add space to separate operators
            }
            stack.push(token);
        } else if (token == '*' || token == '/') {
            while (!stack.isEmpty() && (stack.read_top() == '*' || stack.read_top() == '/')) {
                postfix += stack.pop();
                postfix += ' '; // Add space to separate operators
            }
            stack.push(token);
        }
    }

    // get the remaining operand in the stack after the string is read
    while (!stack.isEmpty()) {
        postfix += stack.pop();
        postfix += ' '; // Add space to separate operators
    }

    return postfix;
}

float Calculator::evaluate() {
    Stack<float> stack; // stack to evaluate
    char* token;
    float operand1, operand2;
    float val = 0;

    token = strtok(&postfix[0], " ");
    while(token){
        if (isdigit(token[0])) {
            stack.push(atof(token));
        }
        else { // token is an operator
            operand2 = stack.pop();
            operand1 = stack.pop();
            switch(token[0]) {
                case '+':
                    val = operand1 + operand2;
                    break;
                case '-':
                    val = operand1 - operand2;
                    break;
                case '*':
                    val = operand1 * operand2;
                    break;
                case '/':
                    val = operand1 / operand2;
                    break;
            }
            stack.push(val);
        }
        // keep on the tokenization
        token = strtok(NULL, " ");
    }
    // get the result of evaluatuiion
    return stack.pop();
}
