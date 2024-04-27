//
// Created by Christopher Buhendwa on 4/27/24.
//

#ifndef ASSIGNMENT_7_CONTACT_H
#define ASSIGNMENT_7_CONTACT_H

#include <string> // Include the necessary header for string

struct Element {
    std::string name;
    int id;
    std::string email;
};

struct stack_node {
    Element data;
    stack_node* link;
};

class Contact {
private:
    stack_node* top;
public:
    Contact();
    ~Contact();
    void Push(Element element);
    Element Pop();
    bool IsEmpty();
    stack_node* GetTop();
    void Print();
    Element* StrToContact(char* line);
    std::string trim(std::string s);
};

#endif //ASSIGNMENT_7_CONTACT_H
