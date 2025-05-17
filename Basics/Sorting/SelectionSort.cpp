//Sorting - Selection Sort  - "	Select minimum and swap.

#include <bits/stdc++.h>
using namespace std;


void selectionSort(int arr[], int n){
	
	for(int i=0;i<n-1;i++){
		
		int min = i;
		
		for(int j=i;j<n;j++){
			
			if(arr[j]<arr[min]){
				
				min = j;
			}
			
			
		}
		
		swap(arr[i],arr[min]);
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
	
	selectionSort(arr,n);
	
	
	
	
	cout<<"Sorted Array"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

//TC- code runs for n+n-1+n-2+n-3....2+1 = sum of n natural numbers = 
//n(n+1)/2 -> n^2/2 + n/2  -> ignore constants
//TC - O(n^2) - best,average,worst
