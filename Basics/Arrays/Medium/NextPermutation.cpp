#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&vec) {
    int n=vec.size();
    int ind =-1;

    for (int i=n-2;i>=0;i--){
        if (vec[i]<vec[i+1]){
            ind=i;
            break;
        }
    }

    if (ind==-1) {
        reverse(vec.begin(),vec.end());
    }

    for (int i=n-1;i>ind;i--) {
        if (vec[i]>vec[ind]) {
            swap(vec[i],vec[ind]);
            break;
        }
    }

    reverse(vec.begin()+ind+1,vec.end());

    for (auto it:vec) {
        cout<<it<<" ";
    }

}



int main(){

    vector<int> vec={3,1,2};

    nextPermutation(vec);

}