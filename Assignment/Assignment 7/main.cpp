//
// Created by Christopher Buhendwa on 4/27/24.
//

#include <fstream>
#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;
int main() {
    Contact* node = new Contact(); // Create an instance of Contact
    string filename;

    cout << "Enter the file name -> " ;
    cin >> filename;

    ifstream inputFile(filename);
    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    string line;
    cout << "----------- input-----------" << endl;
    while (getline(inputFile, line)) {
        // Convert each line of the file into a contact and push it to the stack
        Element* element = node->StrToContact(const_cast<char*>(line.c_str())); // Call member function using arrow operator
        if (element != nullptr) {
            node->Push(*element); // Push the contact to the stack
            delete element; // Clean up allocated memory
        }
        cout << line << endl;
    }

    // Close the file
    inputFile.close();

    cout << "\n----------- Output-----------" << endl;
    node->Print();

    delete node; // Clean up allocated memory for Contact instance

    return 0;
}
