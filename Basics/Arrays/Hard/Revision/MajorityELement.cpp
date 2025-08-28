#include <bits/stdc++.h>
using namespace std;

//merge overlapping sub intervals

void mergeOverlappingSubIntervals(vector<vector<int>>vec) {
    vector<vector<int>> ans;
    int n=vec.size();

    sort(vec.begin(),vec.end());

    for (int i=0;i<n;i++) {
        int start = vec[i][0];
        int end= vec[i][1];

        if (!ans.empty() && ans.back()[1]>=end) {
            continue;
        }

        for (int j=i+1;j<n;j++) {
            if (vec[j][0]<= end) {
                end = max(end,vec[j][1]);
            }
        }

        ans.push_back({start,end});
    }

    for (auto it:ans) {
        cout<<"(";
        for (int num:it) {
            cout<<num<<" ";
        }
        cout<<")"<<endl;
    }
}

void mergeOverlappingSubIntervalsOptimal(vector<vector<int>> vec) {
    int n= vec.size();
    sort(vec.begin(),vec.end());

    vector<vector<int> >ans;

    int start = vec[0][0];
    int end = vec[0][1];

    ans.push_back({start,end});

    for (int i=1;i<n;i++) {
        if (!ans.empty() && ans.back()[1]>=vec[i][1]) {
            continue;
        }
        if (vec[i][0]<=ans.back()[1]) {
            ans.back()[1]=max(ans.back()[1],vec[i][1]);
        }else {
            ans.push_back({vec[i][0],vec[i][1]});
        }
    }

    for (auto it:ans) {
        cout<<"(";
        for (int num:it) {
            cout<<num<<" ";
        }
        cout<<")"<<endl;
    }
}



int main() {
    vector<vector<int>> vec = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    mergeOverlappingSubIntervals(vec);


}