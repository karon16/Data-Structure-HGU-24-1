//
// Created by Christopher Buhendwa on 4/10/24.
//

#include "Queue.h"
#include <iostream>

#define MAX_SIZE 5

using namespace std;

Queue::Queue(){
    front = rear = 0;
    max_size = MAX_SIZE;
    queue = new Element[MAX_SIZE];
}

Queue::Queue(int num){
    front = rear = 0;
    max_size = num;
    queue = new Element[num];
}

Queue::~Queue(){
    delete queue;
}

void Queue::AddQ(Element item) {
    if(IsFullQ()){
        cout << "The queue is full" << endl;
    }else{
        rear = (rear + 1) % max_size;
        queue[rear] = item;
    }

}

Element Queue::DeleteQ() {
    if(IsEmptyQ()){
        cout << "The queue is empty" << endl;
        return (Element)0;
    }else{
        front = (front+1)%max_size;
        return queue[front];
    }
}

void Queue::PrintQ() const {
    for(int i = front ; i <= rear; i++ ){
        cout << queue[i] << endl;
    }
}

bool Queue::IsEmptyQ() const {
    if(front == rear){
        return true;
    }else{
        return false;
    }
}

bool Queue::IsFullQ() const {
    if((rear +1) % max_size == front){
        return true;
    }else{
        return false;
    }
}

