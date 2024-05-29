//
// Created by Christopher Buhendwa on 4/27/24.
//
#include "Contact.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


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

//push element to stack
void Contact::Push(Element element){
    auto *new_node = new stack_node;
    new_node->data = element;
    new_node->link = top;
    top = new_node;
}

Element Contact::Pop() {
    if (top == nullptr) {
        cerr << "The stack is empty" << endl;
        return Element(); // Return a default Element object
    }

    Element element = top->data; // Data to return
    stack_node *del = top; // Node to delete
    top = top->link;
    delete del; // Deallocate the node
    return element;
}

// load data fromn file
bool Contact::load(Contact* contacts) {
    string filename; // filename

    cout << "Enter the file name -> " ;
    cin >> filename; // fet filename

    ifstream inputFile(filename);

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error opening the file" << endl;
        return false;
    }

    string line; // line in file
    while (getline(inputFile, line)) {
        // Convert each line of the file into a contact and push it to the stack
        Element* element = contacts->StrToContact(const_cast<char*>(line.c_str()));
        contacts->Push(*element);// Push the contact to the stack
        delete element;
    }

    // Close the file
    inputFile.close();
    return true;
}

// Insert new contact
void Contact::Insert(Element element) {
    // push new contact to the stack using Push()
    Push(element);
}

//Delete contact by name
void Contact::Delete()  {
    cout << "Enter name of the contact to delete: ";
    string name;
    getline(cin, name);

    // set two nodes for deleting the contact
    stack_node* current = top; // current contact
    stack_node* prev = top; // previous contact

    // if the contact to delete is the top contact, no need to loop
    if(top->data.name == name){
        prev = top;
        PrintContact(top->data);
        top = top->link;
        delete prev;
        return;
    }

    // find the contact to delete and safely remove it pointer from the stack
    while(current){
        if(current->data.name == name){
            break;
        }
        prev = current;
        current = current->link;
    }

    // if contdct not found return
    if(current == nullptr){
        cout << "Contact not found!" << endl;
        return;
    }else{
        PrintContact(current->data);
        cout << "Contact Deleted" << endl;
        prev->link = current->link;
        delete current; // delete contact
    }



}

// Retriece contact by name or email
Element Contact::Retrieve() const {
    string name, email;
    Element element;

    // Ask for choice
    cout << "Search by (1) Name or (2) Email: ";
    int searchChoice;
    cin >> searchChoice;
    cin.ignore();

    // Find by Name or meail
    if (searchChoice == 1) {
        cout << "Enter name: ";
        getline(cin, name);
        element = Find(name);

        //if not found print not found
        if (element.name.empty()) {
            cout << "Contact not found." << endl;
        } else {
            PrintContact(element); // print found contact
        }
    } else if (searchChoice == 2) {
        cout << "Enter email: ";
        getline(cin, email);
        element = Find(email, 2);
        //if not found print not found

        if (element.email.empty()) {
            cout << "Contact not found." << endl;
        } else {
            PrintContact(element); // print found contact
        }
    } else {
        cout << "Invalid command." << endl;
    }

    return element;
}

// Save file report
bool Contact::Save(){
    cout << "Enter filename to save contacts: ";

    string filename;
    getline(cin, filename);

    ofstream output(filename);

    // check if the file is opened succussfuley
    if (!output.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return false;
    }

    stack_node* cur = top;  // set current contact to top

    // loop to write in file
    while (cur) {
        output << toString(cur->data) << endl;
        cur = cur->link;
    }

    output.close(); // close the file
    return true;
}

// Sort using mergeSort
void Contact::Sort() {
    cout << "Sort by (1) Name or (2) Birthday: ";
    int sortChoice;
    cin >> sortChoice; //get choice
    cin.ignore(); // clear new line
    // sort By name
    if (sortChoice == 1) {
        top = mergeSort(top, 1);
    } else if (sortChoice == 2) { // Srt by Birthday
        top = mergeSort(top, 2);
    } else {
        cout << "Invalid command." << endl;
    }
    cout << "Array is sorted" << endl;

}

// Print contacts
void Contact::Print() {
    stack_node* cur;
    for (cur = top; cur != nullptr; cur = cur->link) {
        cout << cur->data.name << "; " << cur->data.birthday << "; " << cur->data.email << "; " << cur->data.phone_number << endl;
    }
}

// Check if empty
bool Contact::IsEmpty() {
    return (top == nullptr);
}

// find contact by name or email helper function
Element Contact::Find(const string& search_value, int search_by) const {
    stack_node* cur = top;

    while (cur != nullptr) {
        //find by name or email
        if ((search_by == 1 && cur->data.name == search_value) ||
            (search_by == 2 && cur->data.email == search_value)) {
            break;
        }
        cur = cur->link;
    }

    if(cur){
        return cur->data;
    }else{

        return Element();
    }
}

// rpint Single contact
void Contact::PrintContact(Element element) const {
    // print contact by using toString helper function
    cout << toString(element) << endl;
}

// toString helper function to print sinble contact
string Contact::toString(Element element) {
    string line;
    line = element.name + "; " + element.birthday + "; " + element.email + "; " + element.phone_number;
    return line;
}

// format contact while reading from file
Element* Contact::StrToContact(char* line) {
    if (line == nullptr)
        return nullptr; // Return nullptr if line is null

    Element* contact = new Element;
    string token;
    istringstream iss(line);

    // Tokenize the input string using ',' as delimiter
    for (int i = 0; getline(iss, token, ';'); ++i) {
        switch (i) {
            case 0: contact->name = trim(token); break;
            case 1: contact->birthday = trim(token); break; // Convert string to integer
            case 2: contact->email = trim(token); break;
            case 3: contact->phone_number = trim(token); break;
        }
    }
    return contact;
}

// trim conact line
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

// split the linked list into two halves
stack_node* Contact::split(stack_node* head) {
    stack_node* slow = head;
    stack_node* fast = head->link;

    // find the middle point by using Floyd's Tortoise Algorithm for Linked list
    while (fast && fast->link) {
        slow = slow->link;
        fast = fast->link->link;
    }

    stack_node* second_half = slow->link;
    slow->link = nullptr;  // Split the list into two halves
    return second_half;
}

//  merge two sorted linked lists
stack_node* Contact::merge(stack_node* first, stack_node* second, int sort_by) {
    // Base cases, when the poniter is null
    if (!first) return second;
    if (!second) return first;
    bool check;

    if(sort_by == 1){
        check =  first->data.name < second->data.name;
    }else{
        check =  first->data.birthday < second->data.birthday;
    }

    // Recursive merge
    if (check) {
        first->link = merge(first->link, second, sort_by);
        return first;
    } else {
        second->link = merge(first, second->link, sort_by);
        return second;
    }
}

// merge sort on the linked list
stack_node* Contact::mergeSort(stack_node *head, int sort_by) {
    // Base case: if head is null or there's only one element
    if (!head || !head->link) {
        return head;
    }

    // Split the list into two halves
    stack_node* second_half = split(head);

    // Recursively sort the two halves
    stack_node* left = mergeSort(head, sort_by);
    stack_node* right = mergeSort(second_half, sort_by);

    // Merge the sorted halves
    return merge(left, right, sort_by);
}
