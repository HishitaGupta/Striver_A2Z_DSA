#include <bits/stdc++.h>
using namespace std;

double time(vector<int > piles, int bananaPerHour) {
    double totalTime =0.0;
    for (int i=0;i<piles.size();i++) {
        totalTime+=ceil((double)piles[i]/(double)bananaPerHour);
    }
    return totalTime;
}

// int minBananaPerHour_Simple(vector<int>piles,int totalHours) {
//
//     int ans =1;
//     int timeTaken = time(piles,ans);
//
//
//     while (timeTaken >= totalHours) {
//         ans++;
//         timeTaken = time(piles,ans);
//     }
//
//     return ans;
// }

int minBananaPerHour_BS(vector<int> piles,int totalHours) {
    int low=1;
    int high=piles[0];
    int ans=-1;
    for (int i=0;i<piles.size();i++) {
        high = max(high,piles[i]);
    }

    while (low<=high) {
        int mid = (low+high)/2;

        if (time(piles,mid)<=totalHours) {
            ans=mid;
            high=mid-1;

        }else {
            low=mid+1;
        }


    }

    return ans;
}

int main() {
    vector<int> piles = {3,6,7,11};
    int totalHours =8;
    // cout<<minBananaPerHour_Simple(piles,totalHours);
    cout<<minBananaPerHour_BS(piles,totalHours);
}