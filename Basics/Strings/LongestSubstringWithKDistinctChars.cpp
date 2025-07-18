#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithKChars_Brute(string s, int k) {

    int res=0;

    for (int i =0;i<s.size();i++) {
        unordered_map<char,int> freq;
        for (int j=i;j<s.size();j++) {
            freq[s[j]]++;
            if (freq.size()==k) {
                res = max(res, j-i+1);
            }else if (freq.size()>k) {
                break;
            }

        }
    }

    return res;
}

int LongestSubstringWithKChars(string s,int k) {
    int n= s.size(); int l=0; int r=0;
    unordered_map<char,int>freq;
    int maxLen=0;

    while (r<n) {
        freq[s[r]]++;

        while (freq.size()>k) {
            freq[s[l]]--;
            if (freq[s[l]]==0) freq.erase(freq[s[l]]);
            l++;
        }

        if (freq.size()<=k) {
            maxLen =max(maxLen,r-l+1);
            r++;
        }


    }

    return  maxLen;
}

int main() {
    string s = "aaabbbcd";
    int k=2;
    cout<<"Length of longest substring with atmost k distinct characters:"<< LongestSubstringWithKChars(s,k);
}