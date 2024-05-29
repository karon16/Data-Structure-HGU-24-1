Sure, here's a `README.md` file for your contact application project:

# Contact Application

## Description
This project is a contact management application that supports the following operations: load, save, insert, delete, retrieve, sort, and print contacts. Each contact consists of a name, birthday, email, and phone number.

## Features
- **Load**: Load contacts from a file into a data structure.
- **Save**: Save the contact data into a file.
- **Insert**: Add a new person to the contacts.
- **Delete**: Delete a person from the contacts by their name (assumes name is a unique key).
- **Retrieve**: Search for a person by name or email and print their information.
- **Sort**: Sort contacts by name or birthday.
- **Print**: Print out all contacts.

## File Format
Each line of the file for loading and saving contacts is in the following format:
```
name; birthday; email; phone_number
```
Example:
```
henry choi; 20190303; hchoi@handong.edu; 010-1234-5678
```

## Usage
1. **Load contacts from a file**:
    ```c++
    contacts.load('contacts.txt')
    ```
2. **Save contacts to a file**:
    ```c++
    contacts.save('contacts.txt')
    ```
3. **Insert a new contact**:
    ```c++
    contacts.insert('John Doe', '19900101', 'johndoe@example.com', '010-1234-5678')
    ```
4. **Delete a contact**:
    ```c++
    contacts.delete('John Doe')
    ```
5. **Retrieve a contact by name or email**:
    ```c++
    contacts.retrieve(name='John Doe')
    contacts.retrieve(email='johndoe@example.com')
    ```
6. **Sort contacts by name or birthday**:
    ```c++
    contacts.sort(by='name')
    contacts.sort(by='birthday')
    ```
7. **Print all contacts**:
    ```c++
    contacts.print()
    ```