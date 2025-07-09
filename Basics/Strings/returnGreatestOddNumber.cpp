#include <bits/stdc++.h>
using namespace std;

string greatestOdd(string s) {
    int n=s.size();

    for (int i=n-1;i>=0;i--) {
        if ((s[i]-'0')%2==1) {
            return s.substr(0, i + 1);
        }
    }
    return " ";
}

int main() {
    string s ="4201";
    cout<<greatestOdd(s);
}