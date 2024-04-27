//
// Created by Christopher Buhendwa on 4/26/24.
//

#ifndef LINKEDLIST_DLIST_H
#define LINKEDLIST_DLIST_H

#include <iostream>

using namespace std;

typedef struct t_list_node {
    string data;
    struct t_list_node *link;
} list_node;

class DList {
private:
    list_node *head;
public:
    DList();
    ~DList();
    list_node* GetHead();
    void delete_list(list_node* node_ptr); // for ~Dlist()
    list_node* Retrieve(string data);
    list_node* Retrieve(int index);
    void Insert(string data);
    void Insert(string data, int index);
    void Delete(string data);
    void Invert();
    void Print();
    bool IsEmpty();
    void Copy(DList* list);
    void Concat(DList* list);
};


#endif //LINKEDLIST_DLIST_H
