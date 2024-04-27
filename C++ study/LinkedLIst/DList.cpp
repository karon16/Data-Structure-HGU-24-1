#include "DList.h"
#include <iostream>

using namespace std;

DList::DList(){
    head = NULL;
}

DList::~DList(){
    delete_list(head);
}

list_node* DList::GetHead(){
    return head;
}

void DList::delete_list(list_node* node_ptr){
    if (node_ptr != NULL) {
        delete_list(node_ptr->link);
        delete node_ptr;
    }
}

void DList::Print() {
    list_node *cur = NULL;
    for (cur = head; cur != NULL; cur = cur->link) {
        cout << cur->data << endl;
    }
}

list_node* DList::Retrieve(string data) {
    list_node *cur = NULL;
    for (cur = head; cur != NULL; cur = cur->link) {
        if (cur->data == data)
            return cur;
    }
    return nullptr;
}

list_node* DList::Retrieve(int index) {
    list_node *cur = head;
    index--;
    int i = 0;
    while (cur != NULL && i < index) {
        cur = cur->link;
        i++;
    }
    return cur;
}

void DList::Insert(string data) {
    list_node *new_node = new list_node;
    new_node->data = data;
    new_node->link = head;
    head = new_node;
}

void DList::Insert(string data, int index) {
    if (index == 0) {
        Insert(data);
        return;
    }

    list_node *new_node = new list_node;
    new_node->data = data;

    list_node *cur = head;
    int i = 0;
    while (cur != NULL && i < index - 1) {
        cur = cur->link;
        i++;
    }

    if (cur == NULL)
        return;

    new_node->link = cur->link;
    cur->link = new_node;
}

void DList::Delete(string data) {
    if (head == nullptr)
        return;

    if (head->data == data) {
        list_node *temp = head;
        head = head->link;
        delete temp;
        return;
    }

    list_node *prev = head;
    list_node *cur = head->link;
    while (cur != nullptr) {
        if (cur->data == data) {
            prev->link = cur->link;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->link;
    }
}

void DList::Invert() {
    if (IsEmpty() || head->link == nullptr)
        return;

    list_node *prev = nullptr;
    list_node *curr = head;
    list_node *next = nullptr;

    while (curr != nullptr) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool DList::IsEmpty() {
    return (head == nullptr);
}

void DList::Copy(DList *list) {
    if (list->IsEmpty()) {
        cout << "The source is empty" << endl;
        return;
    }

    list_node *cur1;
    list_node *cur2;

    cur2 = head;
    for (cur1 = list->GetHead(); cur1 != NULL; cur1 = cur1->link) {
        list_node *new_node = new list_node;
        new_node->data = cur1->data;
        new_node->link = NULL;
        if (IsEmpty()) {
            cur2 = head = new_node;
        } else {
            cur2->link = new_node;
            cur2 = cur2->link;
        }
    }
}

void DList::Concat(DList *list) {
    list_node* cur;
    for(cur= head; cur->link != NULL; cur = cur->link){};

    cur->link = list->GetHead();

}
