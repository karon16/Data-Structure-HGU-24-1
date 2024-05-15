//
// Created by Christopher Buhendwa on 4/10/24.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef int Element;

class Queue {
private:
    int rear, front;
    int max_size;
    Element *queue;

public:
    Queue();
    Queue(int num);
    ~Queue();
    void AddQ(Element item);
    Element DeleteQ();
    void PrintQ() const;
    bool IsFullQ() const;
    bool IsEmptyQ() const;
};


#endif //QUEUE_QUEUE_H
