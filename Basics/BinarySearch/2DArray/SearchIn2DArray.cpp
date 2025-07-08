#include <bits/stdc++.h>
using namespace std;

bool bs(vector<int> vec,int target) {
    int low =0; int high = vec.size()-1;

    while (low<=high) {
        int mid = (low+high)/2;

        if (vec[mid]==target) {
            return true;
        }else if (vec[mid]<target) {
            low=mid+1;
        }else {
            high = mid-1;
        }
    }

    return false;
}

bool searchElement_Better(vector<vector<int>>vec,int target) {
    int m = vec[0].size()-1;
    for (int i=0;i<vec.size();i++) {
        if (vec[i][0]<=target && target <= vec[i][m]) {
            if (bs(vec[i],target)) {
                return true;
            }else {
                return false;
            }
        }
    }

    return false;
}

bool searchElement_BS(vector<vector<int>>vec,int target) {
    int n = vec.size(); int m = vec[0].size();
    int low =0; int high = (n*m)-1;

    while (low<=high) {
        int mid =(low+high)/2;
        int row = mid/m;
        int col = mid%m;

        if (vec[row][col]==target) {
            return true;
        }else if (vec[row][col]<target) {
            low = mid+1;
        }else {
           high=mid-1;
        }
    }

    return false;
}

int main() {

    vector<vector<int>> vec = {
                                    {3,4,5,6},
                                {7,8,9,10},
                                {11,12,13,14},
                                {15,16,17,18}
    };

    // cout << (searchElement_Better(vec, 17) ? "true" : "false") << endl;
    cout << (searchElement_BS(vec, 7) ? "true" : "false") << endl;
}