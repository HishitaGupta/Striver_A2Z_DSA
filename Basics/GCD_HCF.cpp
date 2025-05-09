//Find Greatest Common Divisor or Highest Common Factor
//Brute Force Method 1 - iterate from 1 to n and if n1%i==0 && n2%i==0 make it as gcd . tc-O(n)
//Brute Force 2 but Optimised - iterate from 1 to min(n1,n2) and keep on replacing gcd or min(n1,n2) to i and break 
//because chances are high of finding gcd from end//- tc- O(min(n1,n2))

//Optimised Approach - Euclidean Algorithm - gcd(n1,n2) = gcd(n1-n2,n2) where n1>n2
#include<bits/stdc++.h>
using namespace std;

void findGCD(int a, int b){
	
	while(a>0 && b>0){
		
		if(a>b) a=a%b;
		else b=b%a;
	}
	
	if(a==0) cout<<b;
	else cout<<a;
	
	
}

int main(){
	int a,b;
	cout<<"Enter two Numbers: ";
	cin>>a>>b;
	
	findGCD(a,b);
}
