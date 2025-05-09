//Factorial First N
//Sum of first n numbers

#include <bits/stdc++.h>
using namespace std;


int factorialFirstN(int n){
	
	if(n==0 || n==1){
		return 1;
	}
	
	
	 return n*factorialFirstN(n-1);
	
	
}

int main(){
	int n;
	cout<<"Enter N:";
	cin>>n;
	
	cout<<factorialFirstN(n);
}

//tc- O(n)
//sc-O(n)
