//Recursion
//Print name 5 times

#include<bits/stdc++.h>
#include <string.h>
using namespace std;

int cnt=0;

void printName(const string& name){
	
	if(cnt==5) return;
	
	cout<<name<<endl;
	cnt++;
	printName(name);
}

int main(){
	
	string name;
	cout<<"Enter Name:";
	getline(cin,name);
	
	printName(name);
}

//TC - function runs 5 times so O(n)
//SC - Function is stored in stack for 5 times - O(n)
