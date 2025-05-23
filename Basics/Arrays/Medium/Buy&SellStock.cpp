#include<bits/stdc++.h>
using namespace std;

int buyAndSellStock(vector<int>vec) {
    int n=vec.size();
    int maxProfit =0; int mini = vec[0];

    for (int i=0;i<n;i++) {
        int cost = vec[i]-mini;
        maxProfit=max(maxProfit,cost);
        mini = min(mini,vec[i]);
    }
    return maxProfit;
}



int main(){

    vector<int> vec={7,1,5,3,6,4};


    cout<<buyAndSellStock(vec);

}