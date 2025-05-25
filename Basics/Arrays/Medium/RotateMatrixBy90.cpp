#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> RotateByNinetyBrute(int n,int m,vector<vector<int>> arr) {

    vector <vector <int>> newArr(m,vector<int>(m));

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {

            newArr[j][n-i-1]=arr[i][j];
        }
    }

    return newArr;
}


vector<vector<int>> RotateByNinetyOptimal(int n,int m,vector<vector<int>> &arr) {

    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            swap(arr[i][j],arr[j][i]);
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n/2;j++) {
            swap(arr[i][j],arr[i][n-j-1]);
        }
    }

    return arr;
}



int main() {
    vector<vector<int>> matrix= {
        {1,2,3},
        {4,5,6},
        {7,8,9}
        };

    vector <vector<int>> newArr = RotateByNinetyOptimal(3,3,matrix);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << newArr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}