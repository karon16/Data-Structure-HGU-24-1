//
// Created by Christopher Buhendwa on 4/10/24.
//

#include "Queue.h"
#include <iostream>

using namespace std;

int main(){
    Queue* queue = new Queue(7);

    queue->PrintQ();
    queue->AddQ(1);
    queue->AddQ(3);
    queue->PrintQ();

    cout << "Delete: " << queue->DeleteQ() << endl;
    cout << "Delete: " << queue->DeleteQ() << endl;
    queue->PrintQ();

    return 0;
}
