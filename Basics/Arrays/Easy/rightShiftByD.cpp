//Right Shift By D

#include <bits/stdc++.h>
using namespace std;

void rightShiftByD(int *arr,int n,int d){
	d=d%n;
	
	reverse(arr,arr+d-1);
	reverse(arr+d,arr+n);
	reverse(arr,arr+n);
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
