#include<bits/stdc++.h>
using namespace std;


void sortMatrix(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        vector<vector<int>>sorted;

        for(int i = 0; i < totalRows; i++) {
            for(int j = 0; j < totalCols; j++) {
                vector<int> temp;
                if(i==0 || j==0){
                    int row =i;
                    int col=j;
                    while(row<totalRows && col<totalCols){
                        temp.push_back(grid[row][col]);
                        row++;
                        col++;
                    }
                    if (i<j){sort(temp.begin(),temp.end());}
                    else {sort(temp.begin(), temp.end(), greater<int>());}
                    // sorted.push_back(temp);

                    cout<<"After Sorting";
                    for (auto it: temp) {
                        cout<<it<<" ";
                    }

                    int newRow =i; int newCol=j; int index =0;
                    while(newRow<totalRows && newCol<totalCols){
                        grid[newRow][newCol]=temp[index];
                        newRow++;
                        newCol++;
                        index++;
                    }



                }
            }
        }


    for (auto it : grid) {
        cout<<"{";
        for (auto i: it) {
            cout<<i<<",";
        }
        cout<<"}"<<endl;
    }
   }



int main(){
    vector<vector<int>> vec = {{1,7,3},{9,8,2},{4,5,6}};
    // [[8,2,3],[9,6,7],[4,5,1]]
    sortMatrix(vec);

}