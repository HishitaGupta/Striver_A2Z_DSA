//Hashing

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	
	cout<<"Enter size of array:";
	cin>>n;
	cout<<"Enter array elements:";
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	//precompute
	
	int hash[13]={0};
	for(int i=0;i<n;i++){
		
		hash[arr[i]] +=1;
	}
	
	int q;
	
	cout<<"Enter no. of queries:";
	cin>>q;
	
	while(q--){
		int number;
		cin>>number;
		
		//fetch
		cout<<hash[number]<<endl;
	}
	
	
}

//inside main u can declare array of max 10 raise to power 6 of numbers (bool - 10 raise to power 7)
//outside it can be of 10 raise to power 7 -> int arr[1e7] -> (bool - 10 raise to power 8)
