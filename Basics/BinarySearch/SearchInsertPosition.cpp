#include <bits/stdc++.h>
using namespace std;

void searchInsertPosition(vector <int> vec, int target) {
    int low=0; int high = vec.size()-1;
    int ans=-1;

    while (low<=high) {
       int mid = (low+high)/2;
        if (vec[mid]>=target) {
            ans=mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }

    cout<<ans;
}

int main() {
    vector<int> vec= {1,2,4,7};

    searchInsertPosition(vec,7);
}