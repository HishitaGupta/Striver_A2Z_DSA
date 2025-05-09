//Find if a number is prime or not
//Brute force - iterate from 1 to n and count the number of divisors if count>2 not prime
//Optimised -  iterate from 1 to sqrt(n) or i*i<=n if count==2 prime else not

#include <bits/stdc++.h>
using namespace std;

void FindPrime(int n){
		int count=0;
		
	for (int i=1; i*i<=n;i++){
		
		if(n%i==0 ){
			count++;
			if(n/i != i){
				count++;
			}
			
		}
		
		
	}
	
	if(count==2){
		cout<<"prime";
	}else{
		cout<<"not prime";
	}
}

int main(){
	int n;
	cout<<"Enter N";
	cin>>n;
	
	FindPrime(n);
}
