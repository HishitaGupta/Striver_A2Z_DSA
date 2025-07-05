#include<bits/stdc++.h>;
using namespace std;

void firstLastOccurence_Brute(vector<int> vec , int target) {
    int first=-1; int last =-1;

    for (int i=0;i<vec.size();i++) {
        if (vec[i]==target) {
            if (first==-1) first =i;
            last=i;
        }
    }

    cout<<"{"<<first<<","<<last<<"}";
}

int firstOccurence(vector<int> vec, int target) {
    int low=0; int high=vec.size()-1;
    int first=-1;

    while (low<=high) {
        int mid = (low+high)/2;
        if (vec[mid]==target) {
            first=mid;
            high=mid-1;
        }else if (vec[mid]>target) {
            high = mid-1;
        }else {
            low=mid+1;
        }
    }

    return first;
}

int lastOccurence(vector<int> vec, int target) {
    int low=0; int high=vec.size()-1;
    int last=-1;

    while (low<=high) {
        int mid = (low+high)/2;
        if (vec[mid]==target) {
            last=mid;
            low=mid+1;
        }else if (vec[mid]>target) {
            high = mid-1;
        }else {
            low=mid+1;
        }
    }

    return last;
}


void firstLastOccurence_BS(vector<int>vec,int target) {
   int fs = firstOccurence(vec,target);
    if (fs==-1) cout<<"{-1,0}";
    else {
        cout<<"{"<<fs<<","<<lastOccurence(vec,target)<<"}";
    }
}

pair<int ,int> findLowerBound(vector<int>vec,int target) {
    int low=0; int high=vec.size()-1;
    int ans =-1;

    while (low<=high) {
        int mid =(low+high)/2;

        if (vec[mid]>=target) {
            ans=mid;
            high=mid-1; //to find smallest
        }else {
            low=mid+1;
        }
    }

    if (ans==-1) return {-1,-1};

    return {vec[ans],ans};
}

int findUpperBound(vector<int>vec,int target) {
    int low=0; int high=vec.size()-1;
    int ans =-1;

    while (low<=high) {
        int mid =(low+high)/2;

        if (vec[mid]>target) {
            ans=mid;
            high=mid-1; //to find smallest
        }else {
            low=mid+1;
        }
    }

    return ans;
}

void firstLastOccurence_Practice(vector<int> vec,int target) {
    //find lower bound and upper bound
    //lowerbound=smallest index of that element or element just above it
    //upperbound = smallest index of element just above it

    pair<int,int> lowerBound ;
    int upperBound =-1;

    lowerBound = findLowerBound(vec,target);

    cout<<lowerBound.first;

    if (lowerBound.second==-1 || lowerBound.first!=target) {
        cout<<"{-1,-1}"<<endl;
        return;
    }
    upperBound = findUpperBound(vec,target);

    cout<<"First Occurence:"<<lowerBound.second<<endl;
    cout<<"Last Occurence:"<<upperBound-1<<endl;
}

int main() {
    vector<int>vec ={1,1,1,1,2,4,5,6};
    // firstLastOccurence_Brute(vec,1);
    // firstLastOccurence_BS(vec,1);
    // firstLastoccurence(vec,1); -> using upperbound and lowerbound

    firstLastOccurence_Practice(vec,1); //-> using upperbound and lowerbound
}