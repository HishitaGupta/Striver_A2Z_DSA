#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> coordinates , int minDist , int cows) {
    int cowPlaced =1; int lastCoordinate = coordinates[0];

    for (int i=1;i<coordinates.size();i++) {
        if (coordinates[i]-lastCoordinate >= minDist) {
            cowPlaced+=1;
            lastCoordinate = coordinates[i];
            if (cowPlaced >= cows) return true;
        }
    }

    return false;
}

int findMaxMinDist_Simple(vector<int> &vec, int cows) {
    int n = vec[vec.size()-1]-vec[0];
    sort(vec.begin(),vec.end());
    int ans = INT_MIN;
    for (int i=1;i<=n ;i++) {
        if (isPossible(vec,i,cows)) {
            ans = i;
        }
    }
    return ans;
}

int findMaxMinDist_BS(vector<int> &vec, int cows) {
    int low=1;
    int high = vec[vec.size()-1]-vec[0];
    sort(vec.begin(),vec.end());
    int ans = INT_MIN;

    while (low<=high) {
        int mid = (low+high)/2;

        if (isPossible(vec,mid,cows)) {
            ans=mid;
            low=mid+1; // to find max
        }else {
            high=mid-1; //if not possible then iske bade distance k sath bhi possible nahi hoga
        }
    }
    return ans;
}







int main() {
    vector<int> coordinates = {0,3,4,7,10,9};
    int cows = 4;
    // cout<<findMaxMinDist_Simple(coordinates,cows);
    // cout<<findMaxMinDist_BS(coordinates,cows);
    cout<<findMaxMinDist(coordinates,cows);
}