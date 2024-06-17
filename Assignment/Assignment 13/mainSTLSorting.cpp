//
// Created by Christopher Buhendwa on 6/17/24.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct character{
    char ch;
    int count;
};


using namespace std;

void countWords(vector<character>& character_count, vector<char>& characters){
    bool isFound;
    for(char ch: characters){
        isFound = false;
        for(auto & i : character_count){
            if(isspace(ch)) break;
            if(ch == i.ch){
                (i.count)++;
                isFound = true;
                break;
            }
        }
        if(!isspace(ch) && !isFound){
            character new_char;
            new_char.ch = ch;
            new_char.count = 1;
            character_count.push_back(new_char);
        }
    }
}



bool comparator(const character& c1, const character& c2){
        if (c1.count == c2.count){
            return c1.ch > c2.ch;
        }
    return c1.count > c2.count;

}



int main(){
    string filename; // file name
    vector<char> characters;
    vector<character> character_count;
    cout << "Please enter a file name" << endl;

    cin >> filename;
    ifstream data_file(filename); // open file

    // check if the file is read successfully
    if(!data_file.is_open()){
        cout << "Error opening the file " << filename << endl;
        exit(0);
    }else{
        cout << "[Message]: File opened successfully" << endl;
    }
    char ch;
    while (data_file.get(ch)) {
        characters.push_back(ch);
    }

    // count char frequencies
    countWords(character_count, characters);


    auto size = character_count.size(); //size of the array

    //sort using quick sort
    sort(character_count.begin(), character_count.end(), comparator);


    //print result
    cout << "after sorting using STL ---------" << endl;
    for(int i = 0; i < 10; i++){
        cout << "Char: " << character_count[i].ch << " count:  "<< character_count[i].count << endl;
    }

    return 0;

}