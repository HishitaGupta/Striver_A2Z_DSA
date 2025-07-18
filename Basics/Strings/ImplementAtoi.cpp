#include<bits/stdc++.h>
using namespace std;

int returnInteger(string s) {
    int i=0; int n=s.size();

    //skip spaces
    while (i<n && s[i]==' ') {
        i++;
    }

    //handle sign
    int sign =1;
    while (i<n && (s[i]=='+' || s[i]=='-')) {
        if (s[i]=='-') {
            sign=-1;
        }
        i++;
    }

    //process digits
    long res =0;
    while (i<n && isdigit(s[i])) {
        int digit =s[i]-'0';
        res = res*10 + digit;

        if (res*sign > INT_MAX) return INT_MAX;
        if (res*sign < INT_MIN) return INT_MIN;

        i++;

    }

    return res*sign;
}



int main() {
    string s =" -42abc";

    cout<<returnInteger(s);
}