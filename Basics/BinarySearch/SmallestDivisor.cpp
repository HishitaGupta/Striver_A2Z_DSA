#include <bits/stdc++.h>
using namespace std;

int minN(vector<int> vec) {
    int min = INT_MAX;
    for (int i=0;i<vec.size();i++) {
        if (vec[i]<min) {
            min=vec[i];
        }
    }
    return min;
}

int max(vector<int> vec) {
    int max = INT_MIN;
    for (int i=0;i<vec.size();i++) {
        if (vec[i]>max) {
            max=vec[i];
        }
    }
    return max;
}

int sum(vector<int>vec, int divisor) {
    int sumN =0;
    for (int i=0;i<vec.size();i++) {
        sumN+=ceil((double)vec[i]/(double)divisor);
    }
    return sumN;
}
//
// int smallestDivisor_Simple(vector<int> vec,int threshold) {
//
//     int maxNum= max(vec);
//     int ans = INT_MAX;
//
//     for (int i=1;i<maxNum;i++) {
//         int sumN= sum(vec,i) ;
//         if (sumN<=threshold) {
//             ans = min(ans,i);
//         }
//     }
//
//     return ans;
// }

int smallestDivisor_BS(vector<int>vec,int threshold) {
    int low=1; int high = max(vec);
    int ans = INT_MAX;

    if (vec.size()>threshold) return -1; //if minsum which is equal to number of elements is greater than threshold

    while (low<=high) {
        int mid = (low+high)/2;

        if (sum(vec,mid)<=threshold) {
            ans =mid;
            high=mid-1; //to find the smallest
        }else {
            low=mid+1;
        }
    }
    return ans;
}

int sumPractice(vector<int> vec, int divisor ) {
    int sum=0;
    for (int i=0;i<vec.size();i++) {
        sum+=ceil((double)vec[i]/(double)divisor);
    }
    return sum;
}

int smallestDivisorPractice_Bs(vector<int> vec, int threshold) {
    int low = 1;
    int high = *max_element(vec.begin(),vec.end());
    int ans= 0;

    if (threshold < vec.size()) return 0;

    while (low<=high) {
        int mid = (low+high)/2;

        if (sumPractice(vec,mid) <= threshold) {
            ans = mid;
            high= mid-1;
        }else {
            low=mid+1;
        }
    }

    return ans;
}


int main() {
    vector<int> vec ={1,2,5,9};
    int threshold =6;
   // cout<< smallestDivisor_Simple(vec,threshold);
   // cout<< smallestDivisor_BS(vec,threshold);
   cout<< smallestDivisorPractice_Bs(vec,threshold);
}