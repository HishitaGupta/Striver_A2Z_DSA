#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix_Brute(vector<string> str) {
    int n = str[0].size();
    string prefix;

    for (int i = 0; i < n; i++) {
        char c = str[0][i];
        for (int j = 1; j < str.size(); j++) {
            // if out of bounds OR mismatch
            if (i >= str[j].size() || str[j][i] != c) {
                return prefix; // stop and return what we have so far
            }
        }
        // if all strings had this character, add to prefix
        prefix += c;
    }

    cout << prefix;
    return prefix;
}

string longestCommonPrefix_Better(const vector<string>& str) {
    if (str.empty()) return "";
    string prefix = str[0];

    for (int i=1; i<str.size(); i++) {
        int j=0;
        while (j < prefix.size() && j < str[i].size() && prefix[j] == str[i][j]) {
            j++;
        }
        prefix = prefix.substr(0,j);
        if (prefix.empty()) break;
    }

    return prefix;
}



int main() {
    vector<string> str = {"flower","flow","flight"};
    // cout<<longestCommonPrefix_Brute(str)<<endl;
    cout<<longestCommonPrefix_Better(str)<<endl;
}