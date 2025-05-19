#include <bits/stdc++.h>
using namespace std;

void maximumConsecutiveOnes(int arr[],int n) {
    int consecutive =0, max=0;

    for (int i=0;i<n;i++) {
        if (arr[i]==1) {
            consecutive +=1;
            if (consecutive>max) {
                max=consecutive;
            }

        }else {

            consecutive= 0;
        }
    }

    cout<<max;
}


int main() {

    int n=6;


    int arr[]={1,1,0,1,1,1,};

    maximumConsecutiveOnes(arr,n);


}