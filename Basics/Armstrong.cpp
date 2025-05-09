//Armstrong Number =  sum is equal to each digit raised to power equal to number of digits


#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void checkArmstrong(int n){
	
	int sum=0,digit,count = int(log10(n)+1);
	int original = n;
	
	while(n!=0){
		
		
		digit = n%10;
		sum+= pow(digit,count);
		n=n/10;
		
	}
	
	if (sum == original ){
		cout<<"Armstrong";
	}else{
		cout<<"Not an Armstrong";
	}
}

int main(){
	
	int n;
	
	cout<<"Enter A Number:";
	cin>>n;
	
	checkArmstrong(n);
}


//Time Complexity = O(log(n))
//Space Complexity = O(1)
