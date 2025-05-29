#include <bits/stdc++.h>
using namespace std;

void missingAndRepeatingNumber_Brute(vector<int >vec) {
    for (int i=1;i<=vec.size();i++) {
        int count=0;
        for (int j=0;j<vec.size();j++) {
            if (i==vec[j]) {
                count++;
            }
        }
        if (count==0) {
            cout<<"Missing Number:"<<i<<endl;
        }
        if ( count==2) {
            cout<<"Repeating Number:"<<i;
        }

    }
}

void missingAndRepeatingNumber_Better(vector<int>vec) {
    int n=vec.size();
    int hashArr[n+1]={0};

    for (int i=0;i<n;i++) {
        hashArr[vec[i]]++;
    }

    for (int i=1;i<n+1;i++) {
        if (hashArr[i]==2) {
            cout<<"Repeating Num:"<<i<<endl;
        }
        if (hashArr[i]==0) {
            cout<<"Missing Number:"<<i<<endl;
        }
    }
}
//o(N2)

void missingAndRepeatingNumber_Optimal(vector<int>vec) {
    long long n= vec.size();
    long long s2= (n*(n+1))/2;
    long long squared2= (n*(n+1)*(2*n+1))/6;
    long long s=0,squared1=0;

    for (int i=0;i<n;i++) {
        s+=vec[i];
        squared1+=vec[i]*vec[i];
    }

    long long val1= s-s2; //x-y
    long long val2 = squared1-squared2; //x2-y2 -> (x-y)(x+y)
    val2 = val2/val1; //x+y
    long long x= (val2+val1)/2;
    long long y= val2-x;

    cout<<x<<y;
}
//O(N)


int main() {
    vector<int>vec ={2,3,4,1,1,5};
    // missingAndRepeatingNumber_Brute(vec);
    // missingAndRepeatingNumber_Better(vec);
    missingAndRepeatingNumber_Optimal(vec);
}
