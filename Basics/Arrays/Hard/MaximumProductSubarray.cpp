#include <bits/stdc++.h>
using namespace std;


void maximumProductSubarray_Brute(int *arr,int n) {
    int maxProduct=0;
    for (int i=0;i<n;i++) {
        if (arr[i]<0) continue;
        int product=1;
        for (int j=i;j<n;j++) {
            if (arr[j]<0) {
                product=1;
                continue;
            }
            product*=arr[j];
            maxProduct= max(product,maxProduct);
        }
    }
    cout<<maxProduct;
}

void maximumProductSubarray_Optimal(int *arr,int n) {
    int pre=1; int suff=1;
    int ans=INT_MIN;

    for (int i=0;i<n;i++) {
        if (pre==0) pre=1;
        if (suff==0) suff=1;

        pre= pre*arr[i];
        suff=suff * arr[n-i-1];
        ans=max(ans,max(pre,suff));
    }

    cout<<ans;
}


int main() {
    int arr[]= {3,2,-8,4,3};
    // maximumProductSubarray_Brute(arr,5);
    maximumProductSubarray_Optimal(arr,5);