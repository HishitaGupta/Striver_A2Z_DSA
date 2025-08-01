#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
   vector<pair<int,string>> values ={
       {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
       {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"},
       {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}
   };

    string res;

    for (auto &[val,symbol] : values) {
        while (num >=val) {
            res+=symbol;
            num-=val;
        }
    }

    return res;
}

int main() {
    int num  = 2894;

    cout<<intToRoman(num);
}