#include <bits/stdc++.h>
using namespace std;

void Brute(int arr[],int n) {

    for (int i=0;i<n;i++) {
        int count =0;
        for (int j=0;j<n;j++) {
            if (arr[i]==arr[j]) {
                count++;
            }
        }
        if (count==1) {
            cout<<"Number appearing once:"<<arr[i];
            break;
        }
    }
}

void HashArray(int arr[], int n) {
    int hashArray[n+1] = {0};  // Initialize with zeros

    for (int i = 0; i < n; i++) {  // Loop only till n-1
        hashArray[arr[i]] += 1;
    }

    for (int i = 1; i <= n; i++) {
        if (hashArray[i] == 1) {
            cout << "Missing Number: " << i << endl;
            break;
        }
    }

    for (int i = 0; i <= n; i++) {
        cout << hashArray[i] << " ";
    }
}

void XOR(int arr[],int n) {
    int XOR= 0;
    for (int i=0;i<n;i++) {
        XOR = XOR ^ arr[i];
    }
    cout<<XOR;
}

int main(){
    int n=7;

    int arr[]={1,1,2,2,3,4,4};

    // Brute(arr,n);
    XOR(arr,n);
}