#include <bits/stdc++.h>
using namespace std;

string sortByFrequency_better(string s) {
    unordered_map<char,int> freq;
    for (char c:s) freq[c]++;

    vector <pair<char,int>> vec(freq.begin(),freq.end());
    sort(vec.begin(),vec.end(),[](auto &a,auto &b) {
        return a.second > b.second;
    });

    string res;

    for (auto &p :vec) {
        res.append(p.second,p.first);
    }

    return res;
}

string sortByFrequency_optimal(string s) {
    unordered_map<char,int> freq;
    for (char c:s) freq[c]++;

    int n=s.size();
    vector<vector<char>> buckets(n+1);

    for (auto &[c,f]:freq) {
        buckets[f].push_back(c);
    }

    string res;

    for (int i=n;i>0;i--) {
        for (char c:buckets[i]) {
            res.append(i,c);  //i times c
        }
    }

    return res;
}


int main() {
    // cout<<sortByFrequency_better("tree");
    // cout<<sortByFrequency_optimal("tree");
}