#include <bits/stdc++.h>
using namespace std;

bool ls(vector<int>vec,int el) {
    for (int i=0;i<vec.size();i++) {
        if (vec[i]==el) {
            return true;
        }
    }
    return false;
}

// void longestConsecutiveSequenceBrute(vector<int>vec) {
//    int longest=1; int cnt=0; int  axCnt=0;
//     for (int i=0;i<vec.size();i++) {
//         int x=vec[i];
//         cnt=1;
//         while (ls(vec,x+1)==true) {
//             x=x+1;
//             cnt=cnt+1;
//         }
//         maxCnt=max(cnt,maxCnt);
//
//     }
//
//     cout<<maxCnt;
// }

void longestConsecutiveSequenceBetter(vector<int>vec) {

    sort(vec.begin(),vec.end());
    int n=vec.size(); int cnt=0; int maxCnt=0;

    int lastSmaller = INT_MIN;

    for (int i=0;i<n;i++) {
        if (vec[i]-1 == lastSmaller) {
            cnt++;
            lastSmaller=vec[i];
        }else if (vec[i]!=lastSmaller) {
            lastSmaller=vec[i];
            cnt=1;
        }
        maxCnt=max(cnt,maxCnt);
    }

    cout<<maxCnt;
}

void longestConsecutiveSequenceOptimal(vector <int> vec) {
    unordered_set<int> st;
    for (int i=0;i<vec.size();i++) {
        st.insert(vec[i]);
    }
    int maxCnt=1;
    if (vec.size()==0) cout<<0;

    for (auto it:st) {
        if (st.find(it-1)==st.end()) {
            int cnt=1;
            int x=it;
            while (st.find(x+1)!=st.end()) {
                x=x+1;
                cnt++;
            }
            maxCnt=max(cnt,maxCnt);
        }

    }

    cout<<maxCnt;
}

int main() {
    vector<int> vec= {1,1,2,2,3,3,3,4,4,101,102,103};
    // longestConsecutiveSequenceBetter(vec);

    longestConsecutiveSequenceOptimal(vec);
}
