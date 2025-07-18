#include <bits/stdc++.h>
using namespace std;

int maximumDepth_Brute(string s) {
    stack<int> st; int maxDepth=0;

    for (int i=0;i<s.size();i++) {
        if (s[i]=='(') {
            st.push(s[i]);
            maxDepth = max(maxDepth,(int)st.size());
        }
        if (s[i]==')' && !st.empty()) {
            st.pop();
        }
    }

    return maxDepth;
}

int maximumDepth_Better(string s) {
    int depth = 0; int maxDepth =0;
    for (int i =0;i<s.size();i++) {
        if (s[i]=='(') {
            depth++;
            maxDepth  = max(depth,maxDepth);
        } else if (s[i] == ')') {
            depth--;
        }
    }
    return maxDepth;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<maximumDepth_Brute(s);
    cout<<maximumDepth_Better(s);
}