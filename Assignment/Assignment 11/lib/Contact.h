//
// Created by Christopher Buhendwa on 4/27/24.
//

#ifndef ASSIGNMENT_7_CONTACT_H
#define ASSIGNMENT_7_CONTACT_H

#include <string> // Include the necessary header for string

struct Element {
    std::string name;
    std::string email;
    std::string birthday;
    std::string phone_number;

};

struct stack_node {
    Element data;
    stack_node* link{};
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
//    stack_node* GetTop();
    void Print();
    Element* StrToContact(char* line);
    static std::string trim(std::string s);

    // new functions
    static bool load(Contact* contacts);
    void Insert(Element element);
    void Delete();
    bool Save();
    static std::string toString(Element element) ;
    Element Find(const std::string& search_value, int search_by = 1) const;
    Element Retrieve() const;
    void PrintContact(Element element) const;
    void Sort();
    stack_node* mergeSort(stack_node* head, int sort_by);
    stack_node* merge(stack_node* first, stack_node* second, int sort_by);
    static  stack_node* split(stack_node* head);


};

#endif //ASSIGNMENT_7_CONTACT_H
