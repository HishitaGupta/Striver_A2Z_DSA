#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> vec,int maxSum , int splits) {
    int split =1;
    int sum=0;
    for (int i=0;i<vec.size();i++) {
        if (sum+vec[i]<=maxSum) {
            sum+=vec[i];
        }else {
            split++;
            sum=vec[i];
            if (split==splits) return true;
        }
    }
   return false;
}

int splitArrayLargestSum_BS(vector<int> vec, int splits) {
    int low =*max_element(vec.begin(),vec.end());
    int high = accumulate(vec.begin(),vec.end(),0);
    int result =INT_MAX;

    // for (int i=low;i<high;i++) {
    //     if (isPossible(vec,i,splits)) {
    //         result = min(result,i);
    //     }
    // }

    while (low<=high) {
        int mid = (low+high)/2;

        if (isPossible(vec,mid,splits)) {
            result=mid;
            high=mid-1; // to minimize
        }else {
            low=mid+1;
        }
    }

    return result;
}

int main() {
    vector<int> vec ={10,20,30,40};
    int splits = 2;
    cout<<splitArrayLargestSum_BS(vec,splits);
}