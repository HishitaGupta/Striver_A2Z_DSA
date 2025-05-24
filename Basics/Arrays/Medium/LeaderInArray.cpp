#include<bits/stdc++.h>
using namespace std;

void leaderInArray(vector<int>vec) {
    int n=vec.size();
    int max= INT8_MIN;
    vector<int> ans;

    for (int i=n-1;i>=0;i--) {
        if (vec[i]>max) {
            max=vec[i];
            ans.push_back(vec[i]);
        }
    }

    //order of array - reverse the ans
    //sorted- sort the ans - n log n + n

    for (auto it:ans) {
        cout<<it<<" ";
    }
}

int main(){

    vector<int> vec={1,2,3,2};

    leaderInArray(vec);

}