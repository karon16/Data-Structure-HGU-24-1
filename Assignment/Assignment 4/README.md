## HW4: Contact Application

This document outlines the functionalities and submission guidelines for HW4 - Contact Application.

**Project Description**

We will be implementing a contact application in C with functionalities to manage a list of contacts. This initial phase focuses on loading data from a file and printing the entire contact list.

**Functionalities:**

The Contact application will be implemented as a class with the following operations:

* **load:** Loads contact information from a file into a structure array. (Implemented for HW4)
* **save:** Saves the contact information from the structure array to a file.
* **insert:** Adds a new contact to the structure array.
* **delete:** Deletes a contact from the structure array by name or ID.
* **retrieve:** Searches for a contact by name or ID and displays their information.
* **print:** Prints information of all contacts in the list. (Implemented for HW4)

**File Format:**

The contact information will be stored in a text file with each line representing a single contact in the following format:

```
name; birthday; email; phone_number
```

**HW4 Requirements:**

For HW4, you are required to implement only the following functionalities:

1. **load:** This function should read contact information from the provided data file and store it in a structure array.
2. **print:** This function should iterate through the structure array and print the information of all contacts.

**Skeleton Code and Data File:**

A skeleton code with the necessary header file (`contact_application.h`) and a source file (`contact_answer_in_C.c`) implementing a basic structure is provided at the following link:

**[External Link]** (Access requires Google Drive permission)

**Submission Guidelines:**

* Compress all source files (`.cpp` and `.h`) into a single zip file.
* Submit the zip file following your instructor's guidelines.

**Additional Notes:**

* The provided `contact_answer_in_C.c` file might contain additional functionalities beyond the scope of HW4. You can ignore these for now.
* We will discuss the implementation of remaining functionalities (insert, delete, retrieve) in future assignments.
