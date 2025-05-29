#include <bits/stdc++.h>
using namespace std;

void mergeSameSubIntervals_brute(vector<vector<int>>vec) {
    int n = vec.size();
    vector<vector<int>> ans;
    sort(vec.begin(),vec.end());
    for (int i=0;i<n;i++) {
        int start = vec[i][0];
        int end = vec[i][1];
        if (!ans.empty() && ans.back()[1]>=end) {
            continue;
        }
        for (int j=i+1;j<n;j++) {
            if (vec[j][0]<=end) {
                end=max(end,vec[j][1]);
            }else {
                break;
            }
        }
        ans.push_back({start,end});
    }

    for (auto it:ans) {
        cout<<"(";
        for (int num:it) {
            cout<<num<<" ";
        }
        cout<<")"<<endl;
    }

}


void mergeSubIntervals_optimal(vector<vector<int>> arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }


    for (auto it:ans) {
        cout<<"(";
        for (int num:it) {
            cout<<num<<" ";
        }
        cout<<")"<<endl;
    }
}

int main() {
    vector<vector<int>> vec ={{1,3},{2,6},{8,9},{9,11},
                {8,10},{2,4},{15,18},{16,17}};

    // mergeSameSubIntervals_brute(vec);
    mergeSubIntervals_optimal(vec);
}