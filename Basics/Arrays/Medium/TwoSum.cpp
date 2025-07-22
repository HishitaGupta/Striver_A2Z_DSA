#include <bits/stdc++.h>
using namespace std;

void twoSumBetter(vector <int> vec,int target) {
    map<int,int>mp;
    int n=vec.size();


    for (int i=0;i<n;i++) {
        int rem = target - vec[i];
        if (mp.find(rem) != mp.end()) {
            cout<<"Yes at indices "<<i<<" & "<<mp[rem];
            break;
        }else {
            mp[vec[i]]=i;
        }
    }
}

void twoSumOptimal(vector<int>vec,int target) {
    int i=0; int j=vec.size()-1;

    sort(vec.begin(),vec.end());

    while (i<j) {
        if (vec[i]+vec[j]==target) {
            cout<<i<<" "<<j;
            break;
        }else if (vec[i]+vec[j] > target) {
            j--;
        }else {
            i++;
        }
    }


}

int main(){


    vector<int> vec={2,2,6,8,11};

    vector<int> vec1={2,2,6,8,11};

    // twoSumBetter(vec,14);
    twoSumOptimal(vec,14);

}