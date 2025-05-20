#include <bits/stdc++.h>
using namespace std;

//n^3 complexity
void Brute(int arr[],int n,int s) {
    int longest =0;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int sum=0;
            for (int k=i;k<=j;k++) {
                sum+=arr[k];
            }
            if (sum==s) {
                longest = max(longest,(j-i+1));
            }
        }
    }
    cout<<"Longest subarray with sum "<<s<<"is of length:"<<longest;
}

//n^2
void BruteBetter(int arr[],int n,int s) {
    int longest =0;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum+=arr[j];
            if (sum==s) {
                longest = max(longest,(j-i+1));
            }
        }
    }
    cout<<"Longest subarray with sum "<<s<<"is of length:"<<longest;
}

void Optimal(vector <int> a,long long k) {
    int n=a.size();
    int left=0;
    int right=0;
    long long sum =a[0];
    int maxLen=0;

    while (right<n){
        while (left<=right && sum>k) {
            sum-=a[left];
            left++;
        }
        if (sum==k) {
            maxLen = max(maxLen,(right-left+1));
        }
        right++;
        if (right<n) sum+=a[right];
    }
    cout<< maxLen;
}

int main(){
    int n=7;

    int arr[]={1,1,1,2,2,3,4,4};
    vector<int> a = {1,1,1,2,2,3,4,4};

    // Brute(arr,n,3);
    Optimal(a,3);
}