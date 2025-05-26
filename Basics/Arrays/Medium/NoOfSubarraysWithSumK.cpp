#include <bits/stdc++.h>
using namespace std;

// int SubarraysWithSumK(int arr[],int n,int target) {
//     int left=0;int right=0; int sum=0; int count=0;
//
//
//         while (right<n) {
//             sum+=arr[right];
//             if (sum==target) {
//                 count++;
//                 right++;
//             }else if (sum>target) {
//                 while (sum>target && left<=right) {
//                     sum-=arr[left];
//                     left++;
//                 }
//                 right++;
//             }else {
//                 right++;
//             }
//         }
//
//     return count;
//     }


int SubarraysWithSumK(int arr[],int n,int target) {
    unordered_map<int,int>mp;
    mp[0]=1;
    int count=0; int sum=0;

    for (int i=0;i<n;i++) {
        sum+=arr[i];
        int rem= sum-target;
        if (mp.find(rem)!=mp.end()) {
            count+=mp[rem];
        }
        mp[sum]+=1;
    }

    return count;
}




int main() {
    int arr[]={1,2,3,-3,1,1,1,4,2,-3};

   cout<< SubarraysWithSumK(arr,10,3);
}