#include <bits/stdc++.h>
using namespace std;

//largest subarray with 0 sum

void largestSubarrayWithZeroSum(vector<int> vec) {
    int n= vec.size();
    map<int,int>mp;
    int sum=0;
    int maxLen=0;

    for (int i=0;i<n;i++) {
        sum+=vec[i];
        if (sum==0) {
            maxLen = max(maxLen,i+1);
        }

        if (mp.find(sum)!=mp.end()) {
            maxLen  = max(maxLen , i-mp[sum]);
        }else {
            mp[sum]=i;
        }
    }

    cout<<maxLen;
}



int main() {
    vector<int> vec = {-2,-2,-4,2,3,3,0,1,2,1,8};
    largestSubarrayWithZeroSum(vec);

}