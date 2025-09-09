#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>&vec,int low,int mid,int high) {
    int count=0;
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while (left<=mid && right<=high) {
        if (vec[left]>=vec[right]) {
            temp.push_back(vec[right]);
            right++;
            count += (mid-left)+1;
        }else {
            temp.push_back(vec[left]);
            left++;
        }
    }

    while (left<=mid) {
        temp.push_back(vec[left++]);
    }

    while (right<=high) {
        temp.push_back(vec[right++]);
    }

    for (int i=low;i<=high;i++) {
        vec[i]=temp[i-low];
    }

    return count;
}

int mergeSort(vector <int> &vec,int low,int high) {
    int cnt=0;
    if (low>=high) return cnt;

    int mid =((low+high)/2);


    cnt+=mergeSort(vec,low,mid);
    cnt+=mergeSort(vec,mid+1,high);
    cnt+=merge(vec,low,mid,high);

    return cnt;

}

void countInversionOptimal(vector<int>&vec) {
    int n= mergeSort(vec,0,vec.size()-1);
    cout<<n;
}

void countInversionBrute(vector<int>& vec) {
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                cout << "Inversion: (" << vec[i] << ", " << vec[j] << ")\n";
                count++;
            }
        }
    }
    cout << "Number of Inversions: " << count << endl;
}


int main() {
    vector<int> vec ={5,3,4,2,1};
    countInversionOptimal(vec);
    // countInversionBrute(vec);
}