//Left Rotate an array by n places

#include <bits/stdc++.h>
using namespace std;

void leftRotate(int *arr,int n){
	
	int temp=arr[0];
	
	for(int i=0;i<n;i++){
		
		arr[i]=arr[i+1];
	}
	
	arr[n-1]=temp;
}

int main(){
	
	int n;
	
	cout<<"Enter length of array:";
	cin>>n;
	
	int arr[n];
	 
	cout<<"Enter array elements:";
	
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	leftRotate(arr,n);
	
	cout<<"After Rotating Left:";
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
