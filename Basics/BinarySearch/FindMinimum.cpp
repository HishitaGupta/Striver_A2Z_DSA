#include<bits/stdc++.h>
using namespace std;

void findMinimum(vector<int> vec) {
    int low=0; int high = vec.size()-1;
    int minNum = INT_MAX;

    while (low<=high) {
        int mid = (low+high)/2;

        if (vec[mid]<=vec[high]) {
            //right is sorted
            minNum =min(minNum, vec[mid]);
            high=mid-1;
        }else { //left is sorted
            minNum=min(minNum,vec[low]);
            low=mid+1;
        }
    }

    cout<<minNum;
}

int main() {
    vector<int> vec ={5,6,0,1,2,3,4};
    findMinimum(vec);
}