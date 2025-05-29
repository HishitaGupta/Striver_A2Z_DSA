#include<bits/stdc++.h>
using namespace std;

void mergeUsingSpace(vector<int>vec1,vector<int>vec2) {
    int i=0;
    int j=0;
    int n=vec1.size();
    int m=vec2.size();

    vector<int>merged;

    while (i<n && j<m) {
        if (vec1[i]<=vec2[j]) {
            merged.push_back(vec1[i]);
            i++;
        }else {
            merged.push_back(vec2[j]);
            j++;
        }
    }

    while (i<n) {
        merged.push_back(vec1[i++]);
    }

    while (j<m) {
        merged.push_back(vec2[j++]);
    }

    for (int i=0;i<n+m;i++) {
        if (i<n) vec1[i]=merged[i];
        else vec2[i-n]=merged[i];

    }

    for (int i=0;i<n;i++) {
        cout<<vec1[i]<<" ";
    }
    for (int i=0;i<m;i++) {
        cout<<vec2[i]<<" ";
    }
}

void mergeWithoutSpace(vector<int>vec1,vector<int>vec2) {

    int left=vec1.size()-1;
    int right = 0;

    while (left>=0 && right< vec2.size()) {
        if (vec1[left]>vec2[right]) {
            swap(vec1[left],vec2[right]);
            left--; right++;
        }else {
            break;
        }
    }


    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());

    for (int i=0;i<vec1.size();i++) {
        cout<<vec1[i]<<" ";
    }
    for (int i=0;i<vec2.size();i++) {
        cout<<vec2[i]<<" ";
    }

}

void swapIfGreater(vector<int>&vec1,vector<int>&vec2,int i,int j) {
    if (vec1[i]>vec2[j]) {
        swap(vec1[i],vec2[j]);
    }
}

void mergeUsingGap(vector<int>&vec1,vector<int>&vec2) {
    int n=vec1.size();
    int m=vec2.size();
    int len = n+m;
    int gap= (len/2) + (len%2);

    while (gap>0) {
        int left=0;
        int right=left+gap;

        while (right<len) {
            if (left<n && right>=n) {
                swapIfGreater(vec1,vec2,left,right-n);
            }else if(left>=n) {
                swapIfGreater(vec2,vec2,left-n,right-n);
            }else {
                swapIfGreater(vec1,vec1,left,right);
            }

            left++;right++;

        }
        if (gap==1) break;
        gap=(gap/2)+(gap%2);
    }

    for (int i=0;i<vec1.size();i++) {
        cout<<vec1[i]<<" ";
    }
    for (int i=0;i<vec2.size();i++) {
        cout<<vec2[i]<<" ";
    }

}


int main() {
    vector<int>vec1 = {1,3,5,9};
    vector<int>vec2 ={2,4,8,9};

    // mergeUsingSpace(vec1,vec2);
    // mergeWithoutSpace(vec1,vec2);

    mergeUsingGap(vec1,vec2);
}
