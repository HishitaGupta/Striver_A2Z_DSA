//Sum of first n numbers

#include <bits/stdc++.h>
using namespace std;


int sumFirstN(int n){
	
	if(n==0){
		return 0;
	}
	
	
	 return n*sumFirstN(n-1);
	
	
}

int main(){
	int n;
	cout<<"Enter N:";
	cin>>n;
	
	cout<<sumFirstN(n);
}

//tc- O(n)
//sc-O(n)
