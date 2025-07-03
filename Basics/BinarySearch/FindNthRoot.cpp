#include<bits/stdc++.h>
using namespace std;

int func(int mid,int n,int m) {
    int ans=1;

    for (int i=1;i<=n;i++) {
        ans=ans*mid;
        if (ans>m) return 2;
    }

    if (ans==m) return 1;
    return 0;

}

int findNthRoot(int num,int n) {
    int low=1; int high=num;
    int ans=-1;

    while (low<=high) {
        int mid = (low+high)/2;
        int midN= func(mid,n,num);

        if (midN==1) {
           return mid;
        }

        else if (midN==0) {

            low=mid+1;
        }else {
            high=mid-1;
        }

    }
    return -1;

}


int main() {
    int num,n;
    cout<<"Enter Number to find root of:";
    cin>>num;

    cout<<"Enter n:";
    cin>>n;

    cout<<findNthRoot(num,n);

    // cout<<findNthRootPractice(num,n);
}