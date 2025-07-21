#include <bits/stdc++.h>
using namespace std;

int sumOfBeautyOfSubstrings_Brute(string s) {
    int n=s.size(); int res=0;

    for (int i=0;i<n;i++) {
        vector<int>freq(26,0);
        for (int j=i;j<n;j++) {
            freq[s[j]-'a']++;

            int maxFreq=0; int minFreq=INT_MAX;
            for (int k=0;k<26;k++) {
                if (freq[k]>0) {
                    maxFreq = max(maxFreq,freq[k]);
                    minFreq = min(minFreq,freq[k]);
                }
            }

            res += (maxFreq-minFreq);
        }
    }

    return res;
}


int main() {
    string s ="aab";

    cout<<sumOfBeautyOfSubstrings_Brute(s);
}