#include <bits/stdc++.h>
using namespace std;

void matrixZeroesBrute(int arr[][4],int m,int n) {
     for (int i=0;i<m;i++) {
          for (int j=0;j<n;j++) {
               if (arr[i][j]==0) {
                    for (int k=0;k<m;k++) {
                         if (arr[i][k]!=arr[i][j]) {
                              arr[i][k]=-1;
                         }
                         if (arr[k][j]!=arr[i][j]) {
                              arr[k][j]=-1;
                          }
                    }
               }
          }
     }

     for (int i=0;i<n;i++) {
          for (int j=0;j<n;j++) {
               if (arr[i][j]==-1) {
                    arr[i][j]=0;
               }
          }
     }
}

void matrixZeroesBetter(int n,int m,int arr[][4]) {

     int rows[n]={0},cols[m]={0};

     for (int i=0;i<n;i++) {
          for (int j=0;j<m;j++) {
               if (arr[i][j]==0) {
                    rows[i]=1;
                    cols[j]=1;
               }
          }
     }

     for (int i=0;i<n;i++) {
          for (int j=0;j<m;j++) {
               if (rows[i]==1 || cols[j]==1) {
                    arr[i][j]=0;
               }

          }
     }
}


void matrixZeroesOptimal(int n,int m, int arr[][4]) {
     int col0=1;

     for (int i=0;i<n;i++) {
          for (int j=0;j<m;j++) {
               if (arr[i][j]==0) {
                    arr[i][0]=0;
                 if (j!=0) {
                      arr[0][j]=0;
                 }else {
                      col0=0;
                 }
               }
          }
     }

     for (int i=1;i<n;i++) {
          for (int j=1;j<m;j++) {
               if (arr[i][j]!=0) {
                    if (arr[i][0]==0 || arr[0][j]==0) {
                         arr[i][j]=0;
                    }
               }
          }
     }

     if (arr[0][0]==0) {
          for (int j=0;j<m;j++) {
               arr[0][j]=0;
          }
     }

     if (col0==0) {
          for (int i=0;i<n;i++) {
               arr[i][0]=0;
          }
     }
}




int main() {
     int matrix[4][4]= {
          {1,1,1,1},
          {1,0,0,1},
          {1,1,0,1},
          {1,1,1,1}};

     matrixZeroesOptimal(4,4,matrix);

     for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
               cout << matrix[i][j] << " ";
          }
          cout << "\n";
     }

     return 0;
}