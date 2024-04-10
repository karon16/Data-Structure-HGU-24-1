//
// Created by Christopher Buhendwa on 4/10/24.
//

#include "Stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack* stack = new Stack(3);
    Element *item;

    item = new Element;
    item->key = 1; item->data= "Hello";
    stack->Push(item);

    item = new Element;
    item->key = 2; item->data= "World";
    stack->Push(item);

    stack->Print();

    item = stack->Pop();
    if(item) cout << "Pop: " << item->key << endl;
    stack->Print();

    return 0;
}