//print 1 to n using recursion

#include <bits/stdc++.h>
using namespace std;

void oneToN(int n){
	
	if(n==0){
		return;
	}
	oneToN(n-1);
	cout<<n;
	
	
}

void nToOne(int n){
	
	if(n==0){
		return;
	}
	cout<<n<<" ";
	nToOne(n-1);
}

int main(){
	int n;
	cout<<"Enter Number:";
	cin>>n;
	
//	oneToN(n);
	nToOne(n);
}

//TC- O(n)
//SC - O(n)
