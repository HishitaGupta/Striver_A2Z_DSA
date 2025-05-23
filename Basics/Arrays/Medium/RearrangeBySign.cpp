#include <bits/stdc++.h>
using namespace std;

void RearrangeBySignBrute(vector<int>& vec) {
    int n = vec.size();
    vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++) {
        if (vec[i] >= 0)
            pos.push_back(vec[i]);
        else
            neg.push_back(vec[i]);
    }

    int i = 0, p = 0, ne = 0;

    // Alternately place positives and negatives
    while (p < pos.size() && ne < neg.size()) {
        vec[i++] = pos[p++];
        vec[i++] = neg[ne++];
    }

    // If positives are left
    while (p < pos.size()) {
        vec[i++] = pos[p++];
    }

    // If negatives are left
    while (ne < neg.size()) {
        vec[i++] = neg[ne++];
    }
}

void RearrangeBySignOptimal(vector<int>vec) {
    int n=vec.size();
    int ans[n];
    int pos=0; int neg=1;

    for (int i=0;i<n;i++) {
        if (vec[i]>=0) {
            ans[pos]=vec[i];
            pos=pos+2;
        }else {
            ans[neg]=vec[i];
            neg=neg+2;
        }
    }

    for (int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
}


int main(){

    vector<int> vec={-2,-2,8,9};


    // RearrangeBySignBrute(vec);
    RearrangeBySignOptimal(vec);



}

