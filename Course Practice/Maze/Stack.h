//
// Created by Christopher Buhendwa on 4/10/24.
//

#ifndef MAZE_STACK_H
#define MAZE_STACK_H

typedef struct{
    short int row;
    short int col;
    short int dir;
}Element;

class Stack {
private:
    int top;
    int max_size;
    Element *stack;

public:
    Stack();
    Stack(int num);
    ~Stack();
    bool IsFullS() const;
    bool IsEmptyS() const;
    void Push(Element item);
    Element Pop();
    void Print () const;
};


#endif //MAZE_MAZE_H
