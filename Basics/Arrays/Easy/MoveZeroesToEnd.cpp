#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(int *arr,int n) {
    int j=-1;
    for (int i=0;i<n;i++) {
        if (arr[i] == 0) {
            j=i;
            break;
        }
    }

    for (int i=j+1;i<n;i++) {
        if (arr[i]!=0) {
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main() {
    int n;
    cout<<"Enter length of array:";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements:";

    for (int i=0;i<n;i++) {
        cin>>arr[i];

    }

    moveZeroesToEnd(arr,n);

    cout<<"Array after moveZeroesToEnd:";
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }


}
