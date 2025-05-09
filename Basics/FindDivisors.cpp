//Print All Divisors
//Brute Force - Iterate from 1 to n and check n%i == 0;
//Optimised Solution  - if n%i==0 then n/i = other factor , also iterate half from 1 to sqrt(n) or i*i<n

#include <bits/stdc++.h>
using namespace std;

void findDivisors(int n){
	
	vector<int> vec;
	
	for (int i=1; i*i <= n ; i++){
		if(n%i==0){
			vec.push_back(i);
		}
		
		if(n!=i){
			vec.push_back(n/i);
		}
	}
	
	sort(vec.begin(),vec.end());
	
	for(auto it : vec){
		
		cout<<it<<" ";
	}
	
}

int main(){
	int n;
	cout<<"Enter Number:";
	cin>>n;
	
	findDivisors(n);
}

//Time Complexity = Loop for finding divisors: O(vn)

//Sorting: O(vn log n)

//Overall Time Complexity: O(vn log n)

//Space Complexity: O(vn)
