#include <bits/stdc++.h>
using namespace std;

int numbersTill(vector<vector<int>>vec , int number) {

    int n = vec.size(); int m = vec[0].size();
    int count =0;
    for (int i=0;i<n;i++) {
        int low =0; int high = m-1;
        while (low<=high) {
            int mid =(low+high)/2;

            if (vec[i][mid] <= number) {
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        count+=low;
    }

    return count;
}


int findMedian (vector<vector<int>> vec) {
    int n = vec.size(); int m=vec[0].size();
    int low = INT_MAX; int high = INT_MIN;
    for (int i=0;i<n;i++) {
        if (vec[i][0]<low) {
            low = vec[i][0];
        }
        if (vec[i][m-1]>high) {
            high = vec[i][m-1];
        }
    }

    int medianSize =(n*m)/2;

    while (low<=high) {
        int mid =(low+high)/2;

        if (numbersTill(vec,mid)<=medianSize) {
            low=mid+1;
        }else {
            high =mid-1;
        }
    }
    return low;
}

int main() {
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};

    cout<<findMedian(vec);

}