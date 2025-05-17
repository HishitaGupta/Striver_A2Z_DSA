//Character Hashing

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string str;
	cout<<"Enter String:";
	cin>>str;
	
	//precompute
	int hash[256] ={0};
	
	for(int i=0;i<str.size();i++){
		
		hash[str[i]] +=1;
	}
	
	int q;
	cin>>q;
	
	while(q--){
		char c;
		cin>>c;
		
		cout<<hash[c]<<endl;
	}
}
