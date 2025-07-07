#include <bits/stdc++.h>
using namespace std;

int findKthElement(vector<int> vec1, vector<int>vec2, int k) {
    int n1 = vec1.size(); int n2 = vec2.size();
    if (n1>n2) return findKthElement(vec2,vec1,k);
    int low=max(k-n2,0); int high = min(k,n1    ); int n3=n1+n2;
    int left = k;

    while (low<=high) {
        int mid1 = (low+high)/2;
        int mid2 = left-mid1;
        int l1 = INT_MIN; int l2 = INT_MIN;
        int r1 = INT_MAX; int r2 = INT_MIN;
        if (mid1< n1) r1= vec1[mid1];
        if (mid1< n2) r2= vec2[mid2];
        if (mid1-1 >= 0) l1 = vec1[mid1-1];
        if (mid2-1 >= 0) l2 = vec2[mid2-1];

        if (l1<r2 && l2<r1) {
            return max(l1,l2);
        }else if (l1>r2) {
            high = mid1-1;
        }else {
            low=mid1+1;
        }
    }

    return 0;
}

int main() {
    vector<int> vec1 ={1,3,5,6};
    vector<int> vec2 = {2,4,7,8,9};
    int k =4;
    cout<<findKthElement(vec1,vec2,k);
}