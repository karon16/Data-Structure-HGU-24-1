#include <iostream>
#include "DList.h"

using namespace std;

int main()
{
    DList* list = new DList();
    DList* list2 = new DList();
    list_node* node;

    list->Print();
    cout << "------- Empty" << endl;
    list->Insert("111");
    list->Insert("222");
    list->Insert("333");
    cout << "------- Filled" << endl;

    list->Print();
    list->Invert();
    cout << "--------Inverted list" << endl;
    list->Print();


    node = list->Retrieve(3);
    cout << "------Retrieved node" << endl;
    cout << node->data << endl;


    cout << "------Retrieved node" << endl;
    node = list->Retrieve("333");
    cout << node->data << endl;

    cout << "------List after deletion" << endl;
    list->Delete("333");
    list->Print();

    list2->Copy(list);
//    delete list;

    cout << "------List 1 copyt to list 2 with new added element" << endl;
    list2->Insert("1980");
    list2->Print();

    cout << "------COncatenation" << endl;
    list->Concat(list2);
    list->Print();

//    delete(list);
    delete (list2);
}