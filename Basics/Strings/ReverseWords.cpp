#include<bits/stdc++.h>
using namespace std;

string reverseWords_Brute(string s) {
    stringstream ss(s);
    string word,res;

    while (ss>>word) {
        reverse(word.begin(),word.end());
        if (!res.empty()) res+=' ';
        res+=word;
    }

    return res;
}


string reverseWords_Better(string s) {
    int start=0;

    for (int i=0;i<s.size();i++) {
        if (i==s.size()-1 || s[i]==' ') {
            reverse(s.begin()+start,s.begin()+i);
            start = i+1;
        }
    }

    return s;
}


int main(){
    string s ="Lets do it";

   // cout<<reverseWords_Brute(s);
   cout<<reverseWords_Better(s);

}