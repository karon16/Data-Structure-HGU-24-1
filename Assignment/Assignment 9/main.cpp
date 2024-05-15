//
// Created by Christopher Buhendwa on 5/8/24.
//

#include <iostream>
#include "lib/BinTree.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "lib/Utilities.cpp"

using namespace std;
int main() {
    auto tree = new BinTree();
    node_data data;
    tree_node* found_node = nullptr; // Initialize the pointer

    ifstream dataFile("./Files/data.txt");
    ifstream mapFile("./Files/map.txt");

    if(!dataFile.is_open() || !mapFile.is_open()){
        cerr << "Error opening the files" << endl;
        return 1;
    }

    string line;
    vector<string> tokens;

    while(getline(mapFile, line)){
        tokens  =  Utilities::split(line, ": ");
        data.key = tokens[0];
        data.name = tokens[1];
        tree->insert_node(data);
    }

    string word;
    string revised_text;

    while(dataFile >> word){
        found_node = tree->searchToReplace(word);
        if(found_node != nullptr){
            revised_text += found_node->data.name;
            revised_text += " ";
        }else{
            revised_text += word;
            revised_text += " ";
        }

    }
    cout << revised_text <<  endl;
}

