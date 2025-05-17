 //Insertion Sort - Takes an element and places it in its correct position.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[],int n){
	
	for(int i=0;i<n;i++){
		
		int j=i;
		
		while(j>0 && a[j-1]>a[j]){
			
			swap(a[j-1],a[j]);
			j--;
			
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
	
	insertionSort(arr,n);
	
	cout<<"Sorted Array:";
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

//TC- Best Case - O(n) - there are no swaps
//Average case / Worst Case - O(n^2)
