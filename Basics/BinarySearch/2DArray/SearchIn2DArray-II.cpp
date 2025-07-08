#include <bits/stdc++.h>
using namespace std;

bool searchElementBS(vector<vector<int>>vec , int target){
    int row =0; int col = vec[0].size()-1;
    int n = vec.size(); int m=vec[0].size();

    while (row < n && col >= 0) {
        if (vec[row][col]==target) {
            return true;
        }else if (vec[row][col]>target) {
            col--;
        }else {
            row++;
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
    cout << (searchElementBS(vec, 7) ? "true" : "false") << endl;
}