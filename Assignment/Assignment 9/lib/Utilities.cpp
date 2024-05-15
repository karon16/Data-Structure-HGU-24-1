//
// Created by Christopher Buhendwa on 5/15/24.
//

#include <vector>
#include <iostream>

using namespace std;

class Utilities {
public:
    static vector<string> split(const string& str, const string& delim)
    {
        vector<string> tokens;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == string::npos) pos = str.length();
            string token = str.substr(prev, pos-prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delim.length();
//           Another possible implementation by cutting the orignal string using substr()
//            prev = 0;
//            str.substr(pos + delim.length());
        }
        while (pos < str.length() && prev < str.length());
        return tokens;
    }
};