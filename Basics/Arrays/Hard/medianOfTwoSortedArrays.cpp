#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& nums1, vector<int>& nums2){
    int left=0;
    int right=0;
    int n=nums1.size()-1;
    int m=nums2.size()-1;
        vector<int>merged;
        while(left<=n && right<=m){
            if(nums1[left]<=nums2[right]){
                merged.push_back(nums1[left]);
                left++;
            }else{
                merged.push_back(nums2[right]);
                right++;
            }
        }

        while(left<=n){
            merged.push_back(nums1[left]);
            left++;
        }
        while(right<=m){
            merged.push_back(nums2[right]);
            right++;
        }

        return merged;
    }

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>merged = merge(nums1,nums2);

        int n=merged.size();

        double ans=0;

        if(n%2==0){
            ans= (merged[(n/2)]+merged[((n/2)-1)])/2.0;
        }else{
            ans= merged[(n/2)];
        }

    return ans;
    }

int main() {
    vector<int>vec1 ={1,3,4};
    vector<int>vec2={2,8};

    cout<<findMedianSortedArrays(vec1,vec2);
}