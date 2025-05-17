//Bubble Sort - "	Pushes the maximum to the last by adjacent swaps.

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
		
		for(int i=0;i<n-1;i++){
			int didSwap =0;
			for(int j=0;j<n-i-1;j++){
				if(arr[j]>arr[j+1]){
					swap(arr[j],arr[j+1]);
					didSwap=1;
				}
			}
			if(didSwap=0){
				break;
			}
		}
	
}

int main(){
	int n;
	
	cout<<"Enter length of array:";
	cin>>n;
	
	int arr[n];
	cout<<"Input Array Elements:";
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	bubbleSort(arr,n);
	
	cout<<"Sorted Array:";
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}


//TC- O(n^2) - worst
//Best - O(n) -when there are no swaps break
