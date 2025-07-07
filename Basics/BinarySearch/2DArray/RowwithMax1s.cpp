#include <bits/stdc++.h>
using namespace std;

int count(vector<int>vec) {
    int low=0; int high = vec.size()-1;
    int ans =0;

    while (low<=high) {
        int mid =(low+high)/2;

        if (vec[mid]>=1) {
            ans=mid;
            high=mid-1;
        }else {
            low=mid+1;
        }
    }

    return vec.size()-ans;
}

int rowWithMaxOnes(vector<vector<int>>vec) {
    int n = vec.size();
    int maxCount =0; int maxCountRow =INT_MAX;

    for (int i=0;i<n;i++) {
        if (count(vec[i])>=maxCount) {
            maxCount =count(vec[i]);
            maxCountRow =min(i,maxCountRow);
        }
    }
    return maxCountRow;
}

int main() {
    vector<vector<int>> vec = {{0,0,1,1,1},
                                {0,0,0,1,1},
                                {0,0,0,0,0},
                                    {0,0,1,1,1},
                                    {0,0,0,1,1}};

    cout<<rowWithMaxOnes(vec);
}