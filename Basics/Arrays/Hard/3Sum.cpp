#include<bits/stdc++.h>
using namespace std;

void find3SumBetter(vector<int> vec, int target) {
    set<vector<int>> st;

    int n = vec.size();
    for (int i = 0; i < n; i++) {
        unordered_set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int rem = target - (vec[i] + vec[j]);
            if (hashset.find(rem) != hashset.end()) {
                vector<int> temp = {vec[i], vec[j], rem};
                sort(temp.begin(), temp.end()); // Sort to handle duplicates
                st.insert(temp);
            }
            hashset.insert(vec[j]);
        }
    }

    // Output the results
    for (auto triplet : st) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

void find3SumBrute(vector<int>vec,int target) {
    int n=vec.size();
    set <vector<int>> ans;
    int sum=0;

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                sum = vec[i]+vec[j]+vec[k];
                if (sum==target) {
                    vector<int> temp ={vec[i],vec[j],vec[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
    for (auto triplet : ans) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}


int main() {
    vector<int> vec={-2,0,1,1,1,1,2,5};

    // find3SumBetter(vec,3);
    find3SumBrute(vec,3);
}