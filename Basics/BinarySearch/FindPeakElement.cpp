#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> vec) {
    int n=vec.size();
    if (n==1) return vec[0];
    if (vec[0]>vec[1]) return vec[0];
    if (vec[n-1]>vec[n-2]) return vec[n-1];

    int low=1; int high = n-2;

    while (low<=high) {
        int mid=(low+high)/2;

        if (vec[mid]>vec[mid+1] && vec[mid]>vec[mid-1]) {
            return vec[mid];
        }else if (vec[mid]>vec[mid+1]) {
            high=mid-1;
        }else if (vec[mid]>vec[mid-1]) {
            low=mid+1;
        }else {
            low=mid+1;
        }
    }

    return -1;
}

int findPeakElementPractice(vector<int> vec) {
    int n=vec.size();
    int low = 1; int high = n-2;
    if (n==1) return vec[0];
    if (vec[0]>vec[1]) return vec[0];
    if (vec[n-1]>vec[n-2]) return vec[n-1];

    while (low<=high) {
        int mid = (low+high)/2;
        if (vec[mid]> vec[mid+1] && vec[mid]>vec[mid-1]) {
            return vec[mid];
        }else if (vec[mid - 1] > vec[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}


int main() {
    vector<int> vec ={1,2,3,4,5,8,7,6};
    // cout<<findPeakElement(vec);
    cout<<findPeakElementPractice(vec);
}