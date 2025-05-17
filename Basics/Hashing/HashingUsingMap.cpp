//Number Hashing using map

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter Length of array:";
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	//precompute
	
	map<int,int> mp ;
	for(int i=0;i<n;i++){
		
		mp[arr[i]]+=1;
	}
	
	int q;
	cout<<"Enter Number of queries:";
	cin>>q;
	
	while(q--){
		int number;
		cin>>number;
		
		//fetch
		cout<<mp[number]<<endl;
		
		
	}
}
