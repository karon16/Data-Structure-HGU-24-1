//
// Created by Christopher Buhendwa on 6/17/24.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
            character new_char{};
            new_char.ch = ch;
            new_char.count = 1;
            character_count.push_back(new_char);
        }
    }
}

void swap(vector<character>& array, int first_index, int second_index){
    character temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

int pivot(vector<character>& array, int pivot_index, int end_index){
    int swap_index = pivot_index;
    for(int i = pivot_index+1; i <= end_index; i++){
        if(array[i].count > array[pivot_index].count){
            swap_index++;
            swap(array, swap_index, i);
        }
        else if (array[i].count == array[pivot_index].count){
            if(array[i].ch > array[pivot_index].ch){
                swap_index++;
                swap(array, swap_index, i);
            }
        }
    }
    swap(array, pivot_index, swap_index);
    return swap_index;
}

void quickSort(vector<character>& array, int left_index, int right_index){
    if(left_index >= right_index) return;

    int pivot_index = pivot(array, left_index, right_index);
    quickSort(array, left_index, pivot_index-1);
    quickSort(array, pivot_index+1, right_index);
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
    quickSort(character_count, 0, size-1);


    //print result
    cout << "after sorting ---------" << endl;
    for(int i = 0; i < 10; i++){
        cout << "Char: " << character_count[i].ch << " count:  "<< character_count[i].count << endl;
    }

    return 0;

}