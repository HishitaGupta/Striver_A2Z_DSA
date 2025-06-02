#include<bits/stdc++.h>
using namespace std;

void lowerBound(vector<int>vec,int target) {
    int low=0; int high= vec.size()-1;
    int ans = vec.size();

    while (low<=high) {
        int  mid =(low+high)/2;
        if (vec[mid]>=target) {
            ans = mid; //might be my answer
            high = mid-1;
        }else {
            low = mid+1;
        }
    }

    cout<< ans;
}

void upperBound(vector<int> vec,int target) {
    int low=0; int high = vec.size()-1;
    int ans= vec.size();

    while (low<=high) {
        int mid = (low+high)/2;

        if (vec[mid]>target) {
            ans=mid; //might be my answer
            high = mid-1;
        }else {
            low=mid+1;
        }
    }

    cout<< ans;
}


int main() {
    vector<int > vec ={3,4,5,6,6,7,7};
    // lowerBound(vec,6);
    upperBound(vec,6);
}