#include <bits/stdc++.h>
using namespace std;

// void missingAndRepeatingNumber_Brute(vector<int >vec) {
//     for (int i=1;i<=vec.size();i++) {
//         int count=0;
//         for (int j=0;j<vec.size();j++) {
//             if (i==vec[j]) {
//                 count++;
//             }
//         }
//         if (count==0) {
//             cout<<"Missing Number:"<<i<<endl;
//         }
//         if ( count==2) {
//             cout<<"Repeating Number:"<<i;
//         }
//
//     }
// }
//
// void missingAndRepeatingNumber_Better(vector<int>vec) {
//     int n=vec.size();
//     int hashArr[n+1]={0};
//
//     for (int i=0;i<n;i++) {
//         hashArr[vec[i]]++;
//     }
//
//     for (int i=1;i<n+1;i++) {
//         if (hashArr[i]==2) {
//             cout<<"Repeating Num:"<<i<<endl;
//         }
//         if (hashArr[i]==0) {
//             cout<<"Missing Number:"<<i<<endl;
//         }
//     }
// }
// //o(N2)
//
// void missingAndRepeatingNumber_Optimal(vector<int>vec) {
//     long long n= vec.size();
//     long long s2= (n*(n+1))/2;
//     long long squared2= (n*(n+1)*(2*n+1))/6;
//     long long s=0,squared1=0;
//
//     for (int i=0;i<n;i++) {
//         s+=vec[i];
//         squared1+=vec[i]*vec[i];
//     }
//
//     long long val1= s-s2; //x-y
//     long long val2 = squared1-squared2; //x2-y2 -> (x-y)(x+y)
//     val2 = val2/val1; //x+y
//     long long x= (val2+val1)/2;
//     long long y= val2-x;
//
//     cout<<x<<y;
// }
// //O(N)

void missingAndRepeatingNumber_Better(vector<int> vec) {
    int n = vec.size();
    vector<int>hashmap(n+1,0);

    for (int i=0;i<n-1;i++) {
        hashmap[vec[i]]++;
    }

    for (int i=1;i<=n;i++) {
        if (hashmap[i]==2) {
            cout<<"Repeating num:"<<i<<endl;
        }
        if (hashmap[i]==0) {
            cout<<"Missing num:"<<i;
        }
    }


}

void missingAndRepeatingNumber_Brute(vector<int> vec) {
    int n = vec.size();

    for (int i=1;i<=n;i++) {
        int count =0;
        for (int j=0;j<n;j++) {
            if (i==vec[j]) {
                count++;
            }
        }
        if (count==2) {
            cout<<"Repeating Number:"<<i<<endl;
        }
        if (count==0) {
            cout<<"Missing Number:"<<i<<endl;
        }
    }
}

void missingAndRepeatingNumber_Optimal(vector<int> vec) {
    int n = vec.size();
    long long SN = (n*(n+1))/2;
    long long SN2 = (n*(n+1)*((2*n)+1))/6;

    long long S =0, S2 =0;

    for (int i=0;i<n;i++) {
        S += vec[i];
        S2 +=  vec[i]*vec[i];
    }

    long long val1 = S - SN; // x-y
    long long val = S2- SN2; // x2- y2

    long long val2 = val/val1; //x+y

    long long x = (val1+val2)/2;
    long long  y = val2 - x;

    cout << "Repeating Number:"<<x<<endl;
    cout << "Missing Number:"<<y<<endl;



}


int main() {
    vector<int>vec ={2,3,4,1,1,5};
    // missingAndRepeatingNumber_Brute(vec);
    // missingAndRepeatingNumber_Better(vec);
    missingAndRepeatingNumber_Optimal(vec);
}
