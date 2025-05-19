#include <bits/stdc++.h>
using namespace std;

void linearSearch(int arr[],int n,int f) {
    for (int i=0;i<n;i++) {
        if (arr[i]==f) {
            cout<<f<<" found at index "<<i;
            break;
        }
    }
}

int main() {
    int n;
    cout<<"Enter length of array:";
    cin>>n;

    int arr[n],f;

    cout<<"Enter array elements:";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<"Enter element to be searched:";
    cin>>f;

    linearSearch(arr,n,f);
}