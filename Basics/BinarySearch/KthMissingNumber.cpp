#include <bits/stdc++.h>
using namespace std;

int findKthMissing_BS(vector<int> vec, int k) {
    int low=0; int high = vec.size()-1;

    while (low<=high) {
        int mid = (low+high)/2;

        int missing = vec[mid]-(mid+1);

        if (missing <= k) {
            low=mid+1;
        }else {
            high=mid-1;
        }
    }

    return k + high+1;
}

int findKthMissing_Brute(vector<int> vec, int k) {

    for (int i=0;i<vec.size();i++) {
        if (vec[i]<=k) {
            k++;
        }else {
            return k;
        }
    }
}

int main() {
    vector<int> vec  = {2,3,4,7,11};
    int k =5;
    // cout<<findKthMissing_BS(vec,5);
    cout<<findKthMissing_Brute(vec,5);
}