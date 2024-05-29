//
// Created by Christopher Buhendwa on 4/27/24.
//

#include <fstream>
#include <iostream>
#include <string>
#include "lib/Contact.h"

using namespace std;

void displayMenu() {
    cout << "1.Insert 2.Delete 3.Retrieve 4.Sort 5.Print 6.Save 7.Quit > ";
}

int main() {
    auto* contacts = new Contact(); // Create an instance of Contact

    cout << "Contact Management System" << endl;

    int loaded = Contact::load(contacts);
    int command;
    bool isRunning = true;
    string name, email, birthday, phoneNumber, filename;
    Element element;

    //check if the file is successfully loaded
    if(!loaded){
        return 0;
    }

    do {
        displayMenu();
        cin >> command;
        cin.ignore(); // to clear the newline character from the input buffer

        switch (command) {
            case 1:
                cout << "Enter name: ";
                getline(cin, element.name);
                cout << "Enter birthday (YYYYMMDD): ";
                getline(cin, element.birthday);
                cout << "Enter email: ";
                getline(cin, element.email);
                cout << "Enter phone number: ";
                getline(cin, element.phone_number);
                contacts->Insert(element);
                break;

            case 2:
                contacts->Delete();
                break;
            case 3:
                contacts->Retrieve();
                break;

            case 4:
                contacts->Sort();
                break;
            case 5:
                contacts->Print();
                break;
            case 6:
                if (contacts->Save()) {
                    cout << "Contacts saved successfully." << endl;
                } else {
                    cout << "Error saving contacts." << endl;
                }
                break;
            case 7:
                isRunning = false;
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid command. Please try again." << endl;
                break;
        }
        cout << endl;
    } while (isRunning);

    delete contacts;

    return 0;
}
