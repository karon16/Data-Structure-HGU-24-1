//
// Created by Christopher Buhendwa on 5/15/24.
//

#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

class Utilities {
public:
    // split string function
    static vector<string> split(const string& str, const string& delim){
        vector<string> tokens;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == string::npos) pos = str.length();
            string token = str.substr(prev, pos-prev);
            if (!token.empty()) tokens.push_back(toUpperCase(token));
            prev = pos + delim.length();
//           Another possible implementation by cutting the orignal string using substr()
//            prev = 0;
//            str.substr(pos + delim.length());
        }
        while (pos < str.length() && prev < str.length());
        return tokens;
    }

    // remove ponctuation function
    static string removePonctuation(string& str){
        for (char& i : str) {
            if (ispunct(i)) {
                i = ' ';
            }
        }
        return str;
    }

    // Bring string to uppercase function
    static string toUpperCase(string& str){
        string new_str;
        for (char& c : str) {
            new_str += (char)toupper(c);
        }
        return new_str;
    }

    //count words function
    static void countWords(vector<string> word_list, vector<string>& words, vector<int>& word_count){
        bool isFound;
        for (const auto& i : word_list) {
            isFound = false;
            for (int k = 0; k < words.size(); k++) {
                if (i == words[k]) {
                    word_count[k]++;
                    isFound = true;
                    break;
                }
            }
            if (!isFound) {
                words.push_back(i);
                word_count.push_back(1);
            }
        }
    }

    // quick sort functions
    static void swap(vector<int>& word_count, vector<string>& words, int first_index, int second_index){
        // swap for array of word count
        int temp = word_count[first_index];
        word_count[first_index] = word_count[second_index];
        word_count[second_index] = temp;

        // swap for array of words
        string temp2 = words[first_index];
        words[first_index] = words[second_index];
        words[second_index] = temp2;
    }

    static int pivot(vector<int>& word_count, vector<string>& words, int pivot_index, int end_index) {
        int swap_index = pivot_index;
        int pivot_value = word_count[pivot_index];
        string pivot_string = words[pivot_index];

        for (int i = pivot_index + 1; i <= end_index; i++) {
            if (word_count[i] > pivot_value || (word_count[i] == pivot_value && (words[i] < pivot_string || (words[i] == pivot_string && i > pivot_index)))) {
                swap_index++;
                swap(word_count, words, swap_index, i);
            }
        }

        swap(word_count, words, pivot_index, swap_index);
        return swap_index;
    }

    static void quickSort(vector<int>& word_count, vector<string>& words, int left_index, int right_index){
        if(left_index >= right_index) return;

        int pivot_index = pivot(word_count, words, left_index, right_index);
        quickSort(word_count, words,left_index, pivot_index-1);
        quickSort(word_count, words,pivot_index+1, right_index);
    }

    // print results
    static void printResult(vector<string> words, vector<int> word_count){
        for(int i = 0; i < 5; i++){
            cout << words[i] << " : " << word_count[i] << endl;
        }
    }
};