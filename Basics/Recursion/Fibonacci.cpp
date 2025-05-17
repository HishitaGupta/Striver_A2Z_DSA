//Fibonacci
//Multiple Recurion Calls
// Recursion Treee- depth first

#include <bits/stdc++.h>
using namespace std;


void fibonacciFor( int n){
	int a= 0;
	int b=1;
	
	if(n>=1) cout<<a<<" ";
	if(n >=2) cout<<b<<" ";
	
	for(int i=2;i<n;i++){
		int next = a+b;
		cout<<next<<" ";
		a=b;
		b=next;
	}
}

int fibonacci(int n){
	
	if(n<=1){
		return n;
	}
	
	return fibonacci(n-1)+fibonacci(n-2);
	
	
}

int main(){
	int n;
	
	cout<<"Enter n:";
	cin>>n;
	
	cout<<fibonacci(n);
}

//TC - about O(2^n)
//beacuse each recursion is calling 2 more 
// when n=4 recursion calls=9 which is not ewual to 2^4 but still near
