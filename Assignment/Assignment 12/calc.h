#ifndef  __CALC_H__12
#define  __CALC_H__12

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Calculator {
private:
    string postfix; // Stores the postfix expression

public:
    explicit Calculator(string str); // Constructor
    string infixToPostfix(string infix); // Convert infix to postfix
    float evaluate(); // Evaluate the postfix expression
};

#endif
