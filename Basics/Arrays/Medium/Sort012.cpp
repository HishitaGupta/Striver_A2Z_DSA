#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> & vec) {
    int low =0;
    int mid=0;
    int high = vec.size()-1;

    while (mid <= high) {
        if (vec[mid]==0) {
            swap(vec[mid],vec[low]);
            mid++;
            low++;
        }else if (vec[mid]==1) {
            mid++;
        }else {
            swap(vec[mid],vec[high]);
            high--;
        }
    }
}



int main(){

    vector<int> vec={0,1,1,0,1,2,1,2,0,0,0};

    // twoSumBetter(vec,14);
    sort012(vec);

    cout<<"After Sorting:";
    for (auto it:vec) {
        cout<<it<<" ";
    }

}