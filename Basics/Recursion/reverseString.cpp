//check palindrome in string
//just check if first half is equal to last half
#include <bits/stdc++.h>
using namespace std;

bool reverseString(int i,string &s ){
	
		if(i >= s.size()/2){
			cout<<"Palindrome";
			return true;
		}
		
		if (s[i] != s[s.size()-i-1]){
			cout<<"Not Palindrome";
			return false;
		} 
		
		return reverseString(i+1,s);
}

int main(){
	
	string s;
	cout<<"Enter String:";
	getline(cin,s);
	
	reverseString(0,s);
}
