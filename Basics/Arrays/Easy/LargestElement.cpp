//Largest Element in array - Optimal Aprroach


#include <bits/stdc++.h>
using namespace std;

int largest(int arr[],int n){
	
	int max=arr[0];
	
	for(int i=0;i<n;i++){
		
		if(max<arr[i]){
			max=arr[i];
		}
	}
	
	cout<<"Largest Element:"<<max;
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
	
	largest(arr,n);
}
