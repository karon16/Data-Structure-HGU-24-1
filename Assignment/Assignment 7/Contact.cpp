//
// Created by Christopher Buhendwa on 4/27/24.
//
#include "Contact.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Contact::Contact() {
    top = nullptr;
}

// Keep on popping until the node is empty
Contact::~Contact() {
    while (!IsEmpty()) {
        Pop();
    }
}

void Contact::Push(Element element){
    stack_node *new_node = new stack_node;
    if(new_node == NULL)
        return;
    new_node->data = element;
    new_node->link = top;
    top = new_node;
}

Element Contact::Pop(){
    Element element;
    stack_node *del;
    if(top == NULL)
        cerr << "The stack is Empty" << endl;
        exit(0);
    element = top->data; // data to return
    del = top; // delete node
    top = top->link;
    delete del; // deallocate the node
    return element;
}

void Contact::Print() {
    stack_node* cur = nullptr;
    for (cur = top; cur != nullptr; cur = cur->link) {
        cout << cur->data.id << ", " << cur->data.name << ", " << cur->data.email << endl;
    }
}

bool Contact::IsEmpty() {
    return (top == nullptr);
}

Element* Contact::StrToContact(char* line) {
    if (line == nullptr)
        return nullptr; // Return nullptr if line is null

    Element* contact = new Element;
    string token;
    istringstream iss(line);

    // Tokenize the input string using ',' as delimiter
    for (int i = 0; getline(iss, token, ','); ++i) {
        switch (i) {
            case 0: contact->name = trim(token); break;
            case 1: contact->id = stoi(token); break; // Convert string to integer
            case 2: contact->email = trim(token); break;
        }
    }
    return contact;
}

string Contact::trim(string s) {
    if (s.empty())
        return s; // Return empty string if s is empty

    // Trim leading whitespace
    size_t start = s.find_first_not_of(" \t");
    // Trim trailing whitespace
    size_t end = s.find_last_not_of(" \t");
    if (start == string::npos || end == string::npos)
        return ""; // Return empty string if no non-whitespace characters found
    return s.substr(start, end - start + 1);
}
