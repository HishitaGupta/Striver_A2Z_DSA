#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s,string t){
    if (s.size()!=t.size()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return s==t;
}

bool isAnagram_optimal(string s,string t) {
    if (s.size()!=t.size()) return false;

    vector<int>vec(26,0);

    for (int i=0;i<s.size();i++) {
        vec[s[i]-'a']++;
        vec[t[i]-'a']--;
    }

    for (int count:vec) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main(){
    isAnagram("bat","tab") ? cout<<"True":cout<<"False";
    isAnagram_optimal("bat","tab") ? cout<<"True":cout<<"False";
}