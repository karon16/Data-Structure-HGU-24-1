
#include <string>
#include <fstream>
#include <iostream>
#include "contact.h"

using namespace std;

void Contact::load(string file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cout << "Cannot open " << file_name << endl;
        return;
    }

    string line;
    total_num = 0;
    while (getline(file, line)) {
        persons[total_num++] = str2person(trim(const_cast<char*>(line.c_str())));
    }
    file.close();
}

void Contact::print() {
    for (int i = 0; i < total_num; i++) {
        cout  << persons[i].name << " " << persons[i].dob.year << persons[i].dob.month << persons[i].dob.day << " "
             << persons[i].email << " " << persons[i].phone << endl;
    }
}

Person Contact::str2person(char* line) {
    Person p1;
    char *token;
    int i = 0;

    token = strtok(line, ";");
    while (token) {
        switch (i) {
            case 0: strcpy(p1.name, trim(token)); break;
            case 1: p1.dob = str2date(trim(token)); break;
            case 2: strcpy(p1.email, trim(token)); break;
            case 3: strcpy(p1.phone, trim(token)); break;
        }
        token = strtok(NULL, ";");
        i++;
    }
    return p1;
}

Date Contact::str2date(char* str) {
    Date date;
    char temp[10];
    strncpy(temp, str, 4);
    temp[4] = 0;
    date.year = atoi(temp);

    strncpy(temp, str+4, 2);
    temp[2] = 0;
    date.month = atoi(temp);

    strncpy(temp, str+6, 2);
    temp[2] = 0;
    date.day = atoi(temp);

    return date;
}

char* Contact::trim(char* s) {
    char* ptr;
    if (!s) return nullptr;   // NULL string
    while (isspace(*s)) s++;   // skip left side white spaces
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    *(ptr+1) = '\0';
    return s;
}
