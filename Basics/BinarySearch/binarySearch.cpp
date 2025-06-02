#include<bits/stdc++.h>
using namespace std;

// int searchIterative(vector<int>ans, int target) {
//     int low= 0 , high=ans.size()-1;
//     while (low<=high) {
//         int mid = (low+high)/2;
//
//         if (ans[mid]==target) return mid;
//         else if (ans[mid]<target) low= mid+1;
//         else high=mid-1;
//     }
//
//     return -1;
//
// }

int searchRecursive(vector<int> ans, int low,int high,int target) {

        if (low>high) return -1;

        int mid = (low+high)/2;

        if (ans[mid]==target) return mid;
        else if (ans[mid]>target) return searchRecursive(ans,low,mid-1,target);
        else return searchRecursive(ans,mid+1,high,target);


}

int main(){
    vector<int> ans = {3,4,5,6,7};
    // cout<<searchIterative(ans,5);

    cout<<searchRecursive(ans,0,4,5);
}
