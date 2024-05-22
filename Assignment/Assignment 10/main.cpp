//
// Created by Christopher Buhendwa on 5/12/24.
//


#include <iostream>
#include <fstream>
#include <string>
#include "Utilities.cpp"
#include <vector>

using namespace std;

int main(){
    string filename; // file name
    string line; // lines in file
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

    // get file data and assign to string
    string file_lines;
    while(getline(data_file, line)){
        file_lines += line;
        file_lines += " ";
    }

    // Remove ponctuation
    Utilities::removePonctuation(file_lines);
    // split string into words with space delimiter
    vector<string> word_list = Utilities::split(file_lines, " ");

    vector<string> word;
    vector<int> word_frequency;

    //    cout << "Before the loop" << endl;
    // count words
    Utilities::countWords(word_list, word, word_frequency);


    // sort word and word count arrays
    Utilities::quickSort(word_frequency, word, 0, (int)word_frequency.size()-1);

    //print result;
    Utilities::printResult(word, word_frequency);

    data_file.close(); // close file
    return 0;
}