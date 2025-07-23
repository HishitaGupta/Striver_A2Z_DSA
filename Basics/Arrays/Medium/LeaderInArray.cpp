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

int leaderInArrayBrute(vector<int> vec){
    int leader =-1;

    for (int i=0;i<vec.size();i++){
        for (int j=i+1;j<vec.size();j++){
            leader = vec[i];
            if (vec[i]<vec[j]) {
                leader=-1;
                break;
            }
        }
        if (leader!=-1)  return leader;
    }

    return leader;
}

void leaderInArrayOptimal(vector<int> vec) {
    int max= INT_MIN;
    vector<int>ans;
    for (int i=vec.size()-1;i>=0;i--) {
        if (vec[i]>max) {
            max=vec[i];
            ans.push_back(vec[i]);
        }
    }
    for (auto it : ans) {
        cout<<it<<",";
    }
}


int main(){

    vector<int> vec={1,2,3,0,0,0};

    // leaderInArray(vec);
    // cout<<leaderInArrayBrute(vec);
    leaderInArrayOptimal(vec);

}