#include<bits/stdc++.h>
using namespace std;

void findMajorityNumberBrute(vector<int>vec) {
    int n=vec.size();
    int min = (int)(n/3);
    for (int i=0;i<n;i++) {
        int count=0;
        for (int j=0;j<n;j++) {
            if (vec[i]==vec[j]) {
                count++;

            }

        }
        if (count>min) {
            cout<<vec[i]<<" ";
        }
    }
}

void findMajorityNumberBetter(vector<int> vec) {
    map<int,int> mp;
    list<int> ls;
    int n=vec.size();
    int min= (int)(n/3);
    for (int i=0;i<n;i++) {
        mp[vec[i]]++;
        if (mp[vec[i]]>min) {
            ls.push_back(vec[i]);
        }
        if (ls.size()==min) {
            break;
        }
    }
    for (auto it:ls) {
        cout<<it<<" ";
    }
}

void findMajorityNumberOptimal(vector<int>vec) {
    int n=vec.size();
    int el1 = INT_MIN, el2= INT_MIN;
    int cnt1=0,cnt2=0;
    list<int>ls;

    int min =(int)(n/3);

    for (int i=0;i<n;i++) {
        if (cnt1==0 && el2!=vec[i]) {
            cnt1=1;
            el1=vec[i];
        }else if(cnt2==0 && el1!=vec[i]) {
            cnt2=1;
            el2=vec[i];
        }else if (vec[i]==el1) cnt1++;
        else if (vec[i]==el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0;cnt2=0;
    for (int i=0;i<n;i++) {
        if (el1==vec[i]) {
            cnt1++;
        }
        if (el2==vec[i]) {
            cnt2++;
        }

    }

    if (cnt1>min && ls.size()!=min) {
        ls.push_back(el1);
    }
    if (cnt2>min && ls.size()!=min) {
        ls.push_back(el2);
    }

    for (auto it:ls) {
        cout<<it<<" ";
    }
}

int main() {
    vector<int> vec={1,1,1,1,2,5,3,4};
    // findMajorityNumberBrute(vec);
    // findMajorityNumberBetter(vec);

    findMajorityNumberOptimal(vec);
}
