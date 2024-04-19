#include <iostream>
#include <string>
#include "calc.h"

int main() {
    string str;

    cout << "Input infix expression: ";
    getline(cin, str);    // reading one line from keyboard

    Calculator calc(str);

    cout << "Postfix expression: " << calc.infixToPostfix(str) << endl;
    cout << "Result = " << calc.evaluate() << endl;

    return 0;
}
