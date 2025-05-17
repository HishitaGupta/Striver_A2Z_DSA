//QuickSort
#include <bits/stdc++.h>
using namespace std;


int partition(vector <int> &arr, int low,int high){
		
		int pivot = arr[low];
		int i=low;
		int j=high;
		
		while(i<j){
			while(pivot>=arr[i] && i<=high-1){
				i++;
			}
			while(pivot<arr[j] && j>=low+1){
				j--;
			}
			
			if(i<j){
				swap(arr[i],arr[j]);
			}
		}
		
		swap(arr[low],arr[j]);
		return j;
	
}


void quickSort(vector<int> &arr, int low, int high){
	
	if(low<high){
		
		int pIndex = partition(arr,low,high);
		
		quickSort(arr,low,pIndex-1);
		quickSort(arr,pIndex+1,high);
	}
}


int main(){
	int n;
	
	cout<<"Enter length of array:";
	cin>>n;
	
	vector <int> arr(n) ;
	cout<<"Input Array Elements:";
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	quickSort(arr,0,n-1);
	
	cout<<"Sorted Array:";
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
