#include<bits/stdc++.h>
using namespace std;

void findMajorityElementBrute(vector<int> vec) {
    int n= vec.size();
    int min = (int) n/3;
    int count =0; vector<int>ls;

    for (int i=0;i<n;i++) {
        count =0;
        for (int j=0;j<n;j++) {

            if (vec[j]==vec[i]) {
                count++;
            }

            if (count> min && ls[0]!=vec[i]) {
                ls.push_back(vec[i]);
            }

            if (ls.size()==2) {
                break;
            }

        }





    }
}








int main() {
    vector<int> vec={1,1,1,1,2,5,3,4};
    findMajorityElementBrute(vec);
    // findMajorityNumberBetter(vec);

    // findMajorityNumberOptimal(vec);
}
