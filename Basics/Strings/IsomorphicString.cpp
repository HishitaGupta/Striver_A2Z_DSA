#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic_brute(string s, string t) {
    if (s.size()!=t.size()) return false;

    int n = s.size();

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (s[i]==s[j]) {
                if (t[i]!=t[j]) return false;
            }

            if (t[i]==t[j]) {
                if (s[i]!=s[j]) return false;
            }
        }
    }

    return true;
}

bool isIsomorphic_Optimal(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, char> mapS; // s → t
    unordered_map<char, char> mapT; // t → s

    for (int i = 0; i < s.size(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        // check s → t
        if (mapS.count(c1)) {
            if (mapS[c1] != c2)
                return false; // conflict
        } else {
            mapS[c1] = c2;
        }

        // check t → s
        if (mapT.count(c2)) {
            if (mapT[c2] != c1)
                return false; // conflict
        } else {
            mapT[c2] = c1;
        }
    }
    return true;
}


int main() {
    string s ="add";
    string t ="egg";

    // isIsomorphic_brute(s,t)?cout<<"True":cout<<"False";
    isIsomorphic_Optimal(s,t)?cout<<"True":cout<<"False";
}