#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumBetter (vector<int>vec) {
    int n=vec.size();
    int maxx=0;

    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum+=vec[j];
            maxx=max(sum,maxx);
        }
    }

    return maxx;
}

int maxSubarraySumOptimal(vector<int>vec) {
    int n=vec.size();
    int sum=0; int maxi = LONG_MIN;
    int ansStart=-1,ansEnd = -1;
    for (int i=0;i<n;i++){
        {
            if (sum==0) {
                ansStart=i;
            }
            sum+=vec[i];
            if (sum>maxi) {
                maxi=sum;
                ansEnd=i;
            }
            if (sum<0) {
                sum=0;
            }



        }}
    cout<<"Start:"<<ansStart<<" "<<"End:"<<ansEnd<<endl;
    return maxi;

}


int main(){

    vector<int> vec={-2,-3,4,-1,-2,1,5,-3};

   // cout<<maxSubarraySumBetter(vec);
   cout<<maxSubarraySumOptimal(vec);

}