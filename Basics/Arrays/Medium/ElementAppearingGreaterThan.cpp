#include<bits/stdc++.h>
using namespace std;

void MajorityElementBrute(vector<int>vec) {

    int n=vec.size();

    for (int i=0;i<n;i++) {
        int count=0;
        for (int j=0;j<n;j++) {
            if (vec[i]==vec[j]) {
                count++;
            }
        }

        if (count>n/2) {
            cout<<vec[i];
            break;
        }
    }
}


void MajorityElementBetter(vector<int> vec) {
    int n=vec.size();
    map<int,int>mp;

    for (int i=0;i<n;i++) {
        mp[vec[i]]++;
    }

    for (auto it:mp) {
        if (it.second > (n/2)) {
            cout<<it.first;
        }
    }
}
int MajorityElementOptimal(vector<int>vec) {
    int el; int cnt =0;

    for (int i=0;i<vec.size();i++) {
        if (cnt==0) {
            cnt=1;
            el=vec[i];
        }else if (vec[i]==el) {
            cnt++;
        }else {
            cnt--;
        }
    }
    int cnt1=0;

    for (int i=0;i<vec.size();i++) {
        if (vec[i]==el) cnt1++;
    }
    if (cnt1>(vec.size()/2)) {
        return el;
    }

    return -1;
}

int main(){

    vector<int> vec={1,1,1,1,1,2,1,2,0,0,0};

    // MajorityElementBrute(vec);
   cout<< MajorityElementOptimal(vec);

}