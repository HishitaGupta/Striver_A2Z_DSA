#include<bits/stdc++.h>
using namespace std;

int findElement(int row,int col) {
    int ans=1;
    for (int i=1;i<col;i++) {
        ans=ans*(row-i);
        ans = ans/i;
    }

    return ans;
}

void printRow(int row) {
   int ans=1;
    cout<<1<<" ";
    for (int i=1;i<row;i++) {
        ans=ans*(row-i);
        ans=ans/i;
        cout<<ans<<" ";
    }

}

vector<int> pascalRow(int row) {
    vector<int> ansRow;
    int ans=1;
    ansRow.push_back(ans);
    for (int i=1;i<row;i++) {
        ans=ans*(row-i);
        ans=ans/i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> PascalTriangle(int row) {
    vector<vector<int>> ans;
    for (int i=1;i<=row;i++) {
        vector<int>temp = pascalRow(i);
        ans.push_back(temp);
    }
    return ans;
}


int main(){
    // int row,col;
    // cout<<"Enter row and col:";
    // cin>>row>>col;
    //
    // cout<<findElement(row,col);

    // int rowToPrint;
    // cout<<"Enter row to print:";
    // cin>>rowToPrint;
    //
    // printRow(rowToPrint);

    int n;
    cout<<"Pascal Triangle upto which row?";
    cin>>n;

    vector<vector<int>> ans =PascalTriangle(n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<=i;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}