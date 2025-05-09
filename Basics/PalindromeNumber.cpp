#include <bits/stdc++.h>
using namespace std;

//program to check if a number is palindrome or not

void checkPalindrome(int n){
	int copy,reversedDigit=0,reversedNumber=0;
	copy = n;
	
	while(copy!=0){
		
		reversedDigit = copy%10;
		reversedNumber =  (reversedNumber * 10)+reversedDigit;
		copy=copy/10;
		
	}
	
	cout<<reversedNumber;
	
	if (reversedNumber ==n){
		 cout<<"Palindrome";
	}else{
		cout<<"Not Palindrome";
	}
}

int main(){
	
	int n;
	
	cout<<"Enter Number:";
	cin>>n;
	
	checkPalindrome(n);
}


//Time Complexity = O(int(log10(n)+1)) -> O(log(n))
//Space Complexity = 0(1)
