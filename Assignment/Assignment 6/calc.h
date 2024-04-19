#ifndef  __CALC_H__
#define  __CALC_H__

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class Calculator {
private:
    string postfix; // Stores the postfix expression

public:
    Calculator(string str); // Constructor
    string infixToPostfix(string infix); // Convert infix to postfix
    float evaluate(); // Evaluate the postfix expression
};

#endif
