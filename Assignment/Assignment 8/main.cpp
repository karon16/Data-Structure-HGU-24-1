//
// Created by Christopher Buhendwa on 5/8/24.
//

#include <iostream>
#include "BinTree.h"

using namespace std;
int main() {
    BinTree* tree = new BinTree();
    node_data data;
    tree_node* node_to_delete = nullptr; // Initialize the pointer


    char command;
    bool isRunning = true;

    while(isRunning){
        cin >> command;
        switch (command){
            case 'a':
                cin >> data.key >> data.name;
                tree->insert_node(data);
                break;
            case 'd':
                int key_to_delete;
                cin >> key_to_delete;
                node_to_delete = tree->search_to_delete(key_to_delete);

                if(node_to_delete != nullptr){
                    tree->delete_node(node_to_delete);
                }else{
                    cout << key_to_delete << " is not in the tree" << endl;
                }
//                cout << "delete" << endl;
                break;
            case 'p':
                tree->Print();
                break;
            case 'q':
//                exit(0);
                isRunning = false;
                break;
        }

    }
    tree->Print();
    delete tree;
}

