#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m=mat[0].size();
    int top=0,bottom=n-1;
    int left=0, right=m-1;

    vector<int> ans;

    while (top<=bottom && left<=right) {
        for (int i=left;i<=right;i++) {
            ans.push_back(mat[top][i]);
        }
        top++;
        for (int i=top;i<=bottom;i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        if (top<=bottom){
            for (int i=right;i>=left;i--) {
            ans.push_back(mat[bottom][i]);

        }
            bottom--;
        }

        if (left<=right) {
            for (int i=bottom;i>=top;i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }


    }
    return ans;
}

int main(){
    vector<vector<int>> matrix ={
    {1,2,3,4,5,6},
    {7,8,9,10,11,12},
    {13,14,15,16,17,18},
    {19,20,21,22,23,24},
    {25,26,27,28,29,30},
    {31,32,33,34,35,36}
    };

    vector<int>newMatrix  = spiralMatrix(matrix);

    for (int i=0;i<newMatrix.size();i++) {
       cout<<newMatrix[i]<<" ";
        if ((i+1)%6==0) cout<<endl;

    }
}