//Right Shift By D

#include <bits/stdc++.h>
using namespace std;

// void rightShiftByD(int *arr, int n, int d) {
//     d = d % n;  // handle d > n
//
//
//     reverse(arr, arr + (n-d));
//
//
//     reverse(arr+d+1, arr + n);
//
//
//     reverse(arr , arr + n);
// }

void rightShiftByD(int *arr, int n, int d) {
	d = d % n; // Handle d > n
	if (d == 0) return;

	// Step 1: Reverse the entire array
	reverse(arr, arr + n);

	// Step 2: Reverse first d elements
	reverse(arr, arr + d);

	// Step 3: Reverse the remaining n-d elements
	reverse(arr + d, arr + n);
}

int main(){
	int n;
	cout<<"Enter Length of Array:";
	cin>>n;
	
	int arr[n];
	
	cout<<"Enter array elements:";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	rightShiftByD(arr,n,3);
	
	cout<<"After Right Shift:"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
