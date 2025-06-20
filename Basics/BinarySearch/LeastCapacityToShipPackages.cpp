#include<bits/stdc++.h>
using namespace std;

int maxW(vector<int> vec) {
    int minAns = INT_MIN;
    for (int i=0;i<vec.size();i++) {
        if (vec[i]>minAns) {
            minAns = vec[i];
        }
    }
    return minAns;
}

int calculateDaysRequired(vector<int> weights, int weight) {
    int capacity =0; int days=1;
   for (int i=0;i<weights.size();i++) {
       if (capacity+weights[i]<=weight) {
           capacity+=weights[i];
       }else {
           days+=1;
           capacity=weights[i];
       }
   }
    return days;
}

int leastCapacity_Simple(vector<int> weights, int days) {
    int maxCapacity = 0; int maxWeight = maxW(weights);
    int ans = INT_MAX;
    for (int i=0;i<weights.size();i++) {
        maxCapacity+=weights[i];
    }

    for (int i=maxWeight;i<=maxCapacity;i++) {
        int daysRequired = calculateDaysRequired(weights,i);
        if (daysRequired<=days) {
            ans = min(ans,i);
        }
    }

    return ans;

}

int leastCapacity_BS(vector<int> weights, int days) {
    int high = 0; int low = maxW(weights);
    int ans = INT_MAX;

    for (int i=0;i<weights.size();i++) {
        high+=weights[i];
    }

    while (low<=high) {
        int mid = (low+high)/2;

        int daysRequired = calculateDaysRequired(weights,mid);

        if (daysRequired<=days) {
            ans = mid;
            high=mid-1;
        }else {
            low=mid+1;
        }
    }


    return ans;

}

int main(){
    vector<int> weights ={1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    // cout<<leastCapacity_Simple(weights,days);
    cout<<leastCapacity_BS(weights,days);
}