#include <bits/stdc++.h>
using namespace std;

void findFourSumBrute(vector<int>vec,int target) {
    int n= vec.size();

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                for (int l=k+1;l<n;l++) {
                    int sum = vec[i]+vec[j]+vec[k]+vec[l];
                    if (sum==target) {
                        cout<<"["<<vec[i]<<" "<<vec[j]<<" "<<vec[k]<<" "<<vec[l]<<"]";
                    }
                }
            }
        }
    }
}

void findFourSumBetter(vector<int>vec,int target) {

    set<vector<int>> ans;
    int n=vec.size();
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            unordered_set<int> mp;
            for (int k=j+1;k<n;k++) {
                int rem = target - (vec[i]+vec[j]+vec[k]);
                if (mp.find(rem)!=mp.end()) {
                    vector<int> temp = {vec[i],vec[j],vec[k],(int)(rem)};
                    ans.insert(temp);
                }
                mp.insert(vec[k]);
            }
        }
    }

    for (auto quad : ans) {
        cout<<"[";
        for (int num : quad) {
            cout<<num<<",";
        }
        cout<<"]"<<endl;
    }
}

void findFourSumOptimal(vector<int> vec, int target) {
    set<vector<int>> ans;
    int n = vec.size();
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && vec[i] == vec[i - 1]) continue;  // skip duplicate i

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && vec[j] == vec[j - 1]) continue;  // skip duplicate j

            int k = j + 1, l = n - 1;

            while (k < l) {
                long long sum = (long long)vec[i] + vec[j] + vec[k] + vec[l];

                if (sum == target) {
                    ans.insert({vec[i], vec[j], vec[k], vec[l]});
                    k++;
                    l--;

                    while (k < l && vec[k] == vec[k - 1]) k++;  // skip duplicate k
                    while (k < l && vec[l] == vec[l + 1]) l--;  // skip duplicate l
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    for (auto& quad : ans) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < 3) cout << ",";
        }
        cout << "]\n";
    }
}


int main(){
    vector<int>vec = {-2,-1,9,3,2,1,0,4};
    findFourSumBetter(vec,0);

}