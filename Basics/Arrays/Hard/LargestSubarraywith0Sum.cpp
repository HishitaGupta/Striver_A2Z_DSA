#include<bits/stdc++.h>
using namespace std;

void largestSubarrayZeroSum_Brute(vector<int>vec) {
    int n=vec.size();
    int maxLen=0;
    for (int i=0;i<n;i++) {
        int sum= 0;
        for (int j=i;j<n;j++){
            sum+=vec[j];
            if (sum==0) {
                maxLen= max(maxLen,(j-i+1));
            }
        }

    }
    cout<<maxLen;
}


void largestSubarrayZeroSum_Better(vector<int>vec) {
    int n=vec.size(); int sum=0; int maxLen =0;
    map<int,int>mp;
    for (int i=0;i<n;i++) {
        sum+=vec[i];
        if (mp.find(sum)!=mp.end()) {
            int len = i- mp[sum] ;
            maxLen = max(len,maxLen);
        }
        if (mp.find(sum) == mp.end()) {
            mp[sum]=i;
        }

    }

    cout<<maxLen;
}


int main() {
    vector<int>vec= {1,-1,3,-2,2,-8,1,7,10,23};
    // largestSubarrayZeroSum_Brute(vec);
    largestSubarrayZeroSum_Best(vec);
}
