//left Rotate by n places

#include <bits/stdc++.h>
using namespace std;

//Brute Force
//void leftRotateByD(int *arr, int n,int d){
//	
//	d=d%n;
//	int temp[d];
//	for(int i=0;i<d;i++){ 
//		temp[i]=arr[i];
//	}
//	
//	for(int i=0;i<n;i++){
//		arr[i]=arr[i+d];
//	}
//	
//	for(int i=n-d;i<n;i++){
//		arr[i]=temp[i-(n-d)];
//	}
//}

//Optimal

void leftRotateByN(int *arr,int n,int d){
	reverse(arr,arr+d);
	reverse(arr+d,arr+n);
	reverse(arr,arr+n);
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
	
	leftRotateByD(arr,n,3);
	
	cout<<"After Rotating Left:";
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
