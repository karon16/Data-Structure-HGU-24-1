#include <cstring>
#include "calc.h"
#include <stack>
Calculator::Calculator(string str) {
    postfix = infixToPostfix(str);
}

string Calculator::infixToPostfix(string infix) {
    string postfix;
    stack<char> myStack;

    for (size_t i = 0; i < infix.length(); ++i) {
        char token = infix[i];
//        char next_token = infix[i+]
        if (isdigit(token)) {
            postfix += token;
            if( i < infix.length()  && !isdigit(infix[i+1]) && infix[i+1] != '.'){
                postfix += ' '; // Add space to separate operands
            }
        } else if (token == '(') {
            myStack.push(token);
        } else if (token == ')') {
            while (!myStack.empty() && myStack.top() != '(') {
                postfix += myStack.top();
                myStack.pop();
                postfix += ' '; // Add space to separate operators
            }
            myStack.pop(); // Discard the '('
        } else if (token == '+' || token == '-') {
            while (!myStack.empty() && myStack.top() != '(') {
                postfix += myStack.top();
                myStack.pop();
                postfix += ' '; // Add space to separate operators
            }
            myStack.push(token);
        } else if (token == '*' || token == '/') {
            while (!myStack.empty() && (myStack.top() == '*' || myStack.top() == '/')) {
                postfix += myStack.top();
                myStack.pop();
                postfix += ' '; // Add space to separate operators
            }
            myStack.push(token);
        }else{
            postfix += token;
        }
    }

    // get the remaining operand in the myStack after the string is read
    while (!myStack.empty()) {
        postfix += myStack.top();
        myStack.pop();
        postfix += ' '; // Add space to separate operators
    }

    return postfix;
}

float Calculator::evaluate() {
    stack<float> myStack; // myStack to evaluate
    char* token;
    float operand1, operand2;
    float val = 0;

    token = strtok(&postfix[0], " ");
    while(token){
        if (isdigit(token[0])) {
            myStack.push(atof(token));
        }
        else { // token is an operator
            operand2 = myStack.top();
            myStack.pop();
            operand1 = myStack.top();
            myStack.pop();
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
            myStack.push(val);
        }
        // keep on the tokenization
        token = strtok(nullptr, " ");
    }
    // get the result of evaluatuiion
    float popValue = myStack.top();
    myStack.pop();
    return popValue;
}
