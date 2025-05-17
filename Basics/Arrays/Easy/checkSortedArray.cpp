#include <bits/stdc++.h>
using namespace std;

void checkSorted(int arr[],int n){
	
	int i=0;
	
	while(arr[i]<=arr[i+1] && i<n-1 ){
		
		i++;
	}
	
	if(i==n-1){
		cout<<"Sorted";
	}else{
		cout<<"Not Sorted";
	}
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
	
	checkSorted(arr,n);
}

