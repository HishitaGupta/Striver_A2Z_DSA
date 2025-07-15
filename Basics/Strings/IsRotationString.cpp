#include <bits/stdc++.h>
using namespace std;

bool isRotationStringT_Brute(string s , string t) {

    if (s.size() != t.size()) return false;

    int n= s.size();

    for (int i=0;i<n;i++) {
        string rotation = s.substr(i) + s.substr(0,i);
        if (t==rotation) return true;
    }
}

bool isRotation(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    string concat = s1 + s1;
    return concat.find(s2) != string::npos;
}


int main() {
    string s ="abcd";
    string t ="dabc";

    cout<<isRotationStringT_Brute(s,t);
}