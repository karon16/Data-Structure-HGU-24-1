//
// Created by Christopher Buhendwa on 4/10/24.
//

#include "Stack.h"
#include <iostream>

using namespace std;

#define MAX_STACK_SIZE 10

Stack::Stack(){
    top = -1;
    max_size = MAX_STACK_SIZE;
    stack = new Element*[max_size];
}

Stack::Stack(int num){
    top = -1;
    max_size = num;
    stack = new Element*[max_size];
}

void Stack::Push(Element* item){
    if(IsFullS()){
        cout << "The stack is full" << endl;
    }else{
        stack[++top] = item;
    }
}

Element* Stack::Pop() {
    if(IsEmptyS()){
        cout << "The stack is empty" << endl;
        return NULL;
    }else{
        return stack[top--];
    }
}

void Stack::Print() const {
    for(int i = 0; i <= top; i++){
        cout << stack[i]->key << " " << stack[i]->data << endl;
    }
}

bool Stack::IsFullS() const {
    return (top == max_size-1);
}

bool Stack::IsEmptyS() const {
    return (top == -1);
}