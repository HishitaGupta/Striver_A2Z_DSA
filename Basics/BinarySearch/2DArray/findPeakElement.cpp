#include <bits/stdc++.h>
using namespace std;

int maxElement(vector<vector<int>> vec,int n,int m,int col) {
    int maxElement = -1;
    int maxElementIndex =-1;

    for (int i=0;i<n;i++) {
        if (vec[i][col]>maxElement) {
            maxElement = vec[i][col];
            maxElementIndex = i;
        }
    }
    return maxElementIndex;
}

void findPeakElement(vector<vector<int>>vec) {
    int n= vec.size(); int m = vec[0].size();
    int low = 0; int high = m-1;

    while (low<=high) {
        int mid =(low+high)/2;

        int maxElementIndex = maxElement(vec,n,m,mid);

        int left = mid-1 >= 0 ? vec[maxElementIndex][mid-1] : -1;
        int right = mid+1 <= high ? vec [maxElementIndex][mid+1] : -1;

        if (vec[maxElementIndex][mid] > left && vec[maxElementIndex][mid] > right) {
            cout << vec[maxElementIndex][mid];
            break;
        }
        else if (vec[maxElementIndex][mid] < left) {
            high = mid-1;
        }else {
            low = mid+1;
        }


    }
}

int main() {
    vector<vector<int>> vec = {{3,4,5,6},
                                {7,8,9,10},
                                {11,12,13,14},
                                {15,16,17,18}
                                };
    findPeakElement(vec);
}