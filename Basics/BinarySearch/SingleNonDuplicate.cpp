#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>vec) {
    int n=vec.size();
    if (n==1) return vec[0];

    if (vec[0]!=vec[1]) return vec[0];
    if (vec[n-1]!=vec[n-2]) return vec[n-1];

    int low=0; int high = n-2;

    while (low<=high) {

        int mid =(low+high)/2;

        if (vec[mid]!=vec[mid-1] && vec[mid]!=vec[mid+1]) {
            return vec[mid];
        }

        //we are on left
        if ((mid%2==1 && vec[mid]==vec[mid-1]) || (mid%2==0 && vec[mid]==vec[mid+1])) {
            low=mid+1;
        }else {
            high=mid-1;
        }
    }

    return -1;
}

int main() {
    vector<int>vec = {1,1,2,2,3,3,4,5,5,6,6};

    cout<< singleNonDuplicate(vec);
}