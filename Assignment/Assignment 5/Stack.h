//
// Created by Christopher Buhendwa on 4/10/24.
//

#ifndef ASSIGNMENT_5_STACK_H
#define ASSIGNMENT_5_STACK_H
#include <string>

using namespace std;


typedef struct{
    int key;
    string data;
}Element;

class Stack {
private:
    int top;
    int max_size;
    Element **stack;

public:
    Stack();
    Stack(int num);
    ~Stack();
    bool IsFullS() const;
    bool IsEmptyS() const;
    void Push(Element* item);
    Element* Pop();
    void Print () const;
};


#endif //ASSIGNMENT_5_STACK_H
