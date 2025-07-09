#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    int i = 0, j = 0;

    // Trim leading and trailing spaces and reduce multiple spaces
    string cleaned = "";
    while (i < n) {
        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        if (i >= n) break;

        if (!cleaned.empty()) cleaned += ' ';

        string word = "";
        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        cleaned += word;
    }

    // Reverse entire cleaned string
    reverse(cleaned.begin(), cleaned.end());

    // Reverse each word in the reversed string
    n = cleaned.size();
    i = 0;
    while (i < n) {
        j = i;
        while (j < n && cleaned[j] != ' ') j++;

        reverse(cleaned.begin() + i, cleaned.begin() + j);
        i = j + 1;
    }

    return cleaned;
}

int main() {
    string s = "  The sky   is  Blue  ";
    cout << '"' << reverseWords(s) << '"' << endl;  // Output: "Blue is sky The"
    return 0;
}
}