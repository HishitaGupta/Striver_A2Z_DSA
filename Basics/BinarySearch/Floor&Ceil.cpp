#include<bits/stdc++.h>
using namespace std;

void floor(vector<int> vec , int target) { //largest of num<=target
    int low=0; int high = vec.size()-1;
    int ans = -1;

    while (low<=high) {
        int mid=(low+high)/2;
        if (vec[mid]<=target) { //right
            ans=mid;
            low=mid+1;
        }else {
            high = mid-1;
        }
    }

    cout<<"Floor:"<<ans<<endl;
}

void ceil(vector<int> vec, int target) { //smallest of num>target ->lowerbound
    int low=0; int high = vec.size()-1;
    int ans = -1;

    while (low<=high) {
        int mid=(low+high)/2;
        if (vec[mid]>=target) { //left
            ans=mid;
            high=mid-1;
        }else {
           low = mid+1;
        }
    }

    cout<<"Ceil:"<<ans<<endl;
}


int main() {
    vector<int> vec ={1,1,1,3,4,5,6};
    floor(vec,2);
    ceil(vec,2);
}