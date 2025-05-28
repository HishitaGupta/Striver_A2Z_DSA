#include <bits/stdc++.h>
using namespace std;

void SubarraysWithXOR_brute(vector<int>vec,int target) {
    int xr=0; int cnt=0;

    for (int i=0;i<vec.size();i++) {
        for (int j=i;j<vec.size();j++) {
            xr = xr ^ vec[i];
            if (xr == target) {
                cnt++;
            }
        }
    }
    cout<<cnt;

}

void SubarraysWithXOR_better(vector<int>vec,int target) {
    int xr=0;
    map<int,int>mp;
    mp[0]=1;
    int cnt=0;

    for (int i=0;i<vec.size();i++) {
        xr ^= vec[i];
        int rem = target ^ xr;
        if (mp.find(rem) != mp.end()) {
            cnt += mp[rem];
        }
        mp[xr]+=1;
    }
    cout<<cnt;
}

int main() {
    vector<int> vec ={1,2,3};
    // SubarraysWithXOR_brute(vec,2);
    SubarraysWithXOR_better(vec,2);
}
