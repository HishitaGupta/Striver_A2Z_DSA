#include<bits/stdc++.h>
using namespace std;

void findSqrt(int num) {
    int ans=0;
    for (int i=1;i<=num;i++) {
        if (i*i <= num) {
            ans=i;
        }
        else {
           break;
        }
    }
    cout<<ans;
}

void findSqrtBS(int num) {
    int low=1; int high = num;

    while (low<=high) {
        int mid = (low+high)/2;
        int val =(mid*mid);

        if (val<=num) {
            low=mid+1;
        }else {
            high=mid-1;
        }
    }

    cout<<high;
}

int main() {
    findSqrtBS(30);
}