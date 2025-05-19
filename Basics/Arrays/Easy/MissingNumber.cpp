#include <bits/stdc++.h>
using namespace std;


//Neighbour checking - My Approach
// void findMissing(int arr[],int n) {
//
//     if (arr[0] != 1) {
//         cout << "Missing number is: 1" << endl;
//         return;
//     }
//
//     for (int i=1;i<=n-2;i++) {
//         if (arr[i-1]!=arr[i]-1 || arr[i+1]!=arr[i]+1) {
//             cout<<arr[i]+1;
//             break;
//         }
//     }
// }

void findMissingBrute(int arr[], int n) {
    for (int i = 1; i <= n; i++) { // check all numbers from 1 to n
        bool found = false;
        for (int j = 0; j < n - 1; j++) { // array has n-1 elements
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Missing number is: " << i << endl;
            return;
        }
    }
}

void findMissingBetter(int arr[],int n) {
    int hash[n+1]={0};

    for (int i=0;i<n-1;i++) {
        hash[arr[i]]=1;
    }

    for (int i=1;i<=n;i++) {
        if (hash[i]==0) {
            cout<<i;
            break;
        }
    }
}

void findMissingSum(int arr[],int n) {
    int sum = (n * (n+1) )/2;
    int s2=0;

    for (int i=0;i<n-1;i++) {
        s2+=arr[i];
    }

    cout<<"Missing Number "<<sum-s2;
}

void findMissingXOR(int arr[], int n) {
    int xor1 = 0;  // XOR of 0 to n
    int xor2 = 0;  // XOR of array elements

    for (int i = 0; i < n; i++) {
        xor1 ^= i + 1;    // XOR of numbers from 1 to n (includes n)
        xor2 ^= arr[i];   // XOR of actual elements
    }

    int missing = xor1 ^ xor2;

    cout << "Missing Number: " << missing << endl;
}


int main() {
    int n=6;


    int arr[] = {1,2,3,4,5};

    // findMissingBrute(arr,n);

    // findMissingBetter(arr,n);

    // findMissingSum(arr,n); //Optimal-1

    findMissingXOR(arr,n); //Optimal -2
}