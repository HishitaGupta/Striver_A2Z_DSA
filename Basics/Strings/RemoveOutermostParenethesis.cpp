#include <bits/stdc++.h>
using namespace std;

string removeOuterParenthesis(string s) {
    int depth =0;
    string result ="";

    for (char c:s) {
        if (c =='(') {
            if (depth>0) result +=c;
            depth ++;
        }else if (c ==')') {
            depth--;
            if (depth > 0) result +=c;
        }

    }
    return result;
}

int main() {
    string s = "(()())(())";
    cout << removeOuterParenthesis(s);
    return 0;
}