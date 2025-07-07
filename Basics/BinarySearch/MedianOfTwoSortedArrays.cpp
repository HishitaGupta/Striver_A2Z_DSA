#include<bits/stdc++.h>
using namespace std;


double findMedian_Brute(vector<int>vec1, vector<int>vec2) {
    int n1 = vec1.size(); int n2=vec2.size();
    int i=0;int j=0;
    vector<int>vec3;

    while (i<n1 && j<n2) {
        if (vec1[i]<vec2[j]) {
            vec3.push_back(vec1[i++]);
        }else {
            vec3.push_back(vec2[j++]);
        }
    }

    while (i<n1) {
        vec3.push_back(vec1[i++]);
    }

    while (j<n2) {
        vec3.push_back(vec2[j++]);
    }

    double n3=n1+n2;

    if (vec3.size()%2==1) {
        return (double)vec3[n3/2.0];
    }
        return (double)(vec3[n3/2]+vec3[(n3/2)-1])/2.0;

}

double findMedian_Better(vector<int>vec1, vector<int>vec2) {
    int n1 = vec1.size(); int n2=vec2.size();
    int i=0;int j=0; int count=0;
    int el1Index=(n1+n2)/2;
    int el2Index=((n1+n2)/2)-1;
    double el1=-1.0; double el2=-1.0;


    while (i<n1 && j<n2) {
        if (vec1[i]<vec2[j]) {

            if (count == el1Index) el1=vec1[i];
            if (count == el2Index) el2=vec1[i];
            count++;
            i++;

        }else {

            if (count == el2Index) el2=vec2[j];
            if (count == el1Index) el1=vec2[j];
            count++;
            j++;
        }
    }

    while (i<n1) {

        if (count == el1Index) el1=vec1[i];
        if (count == el2Index) el2=vec1[i];
        count++;
        i++;
    }

    while (j<n2) {

        if (count == el2Index) el2=vec2[j];
        if (count == el1Index) el1=vec2[j];
        count++;
        j++;
    }

    int n3=n1+n2;

    if (n3%2==1) {
        return (double) el1;
    }
    return (double) ((el1+el2)/2.0);

}

double findMedian_BS(vector<int>vec1,vector<int>vec2) {
    int n1=vec1.size();
    int n2 = vec2.size();
    if (n1>n2) return findMedian_BS(vec2,vec1);
    int left = (n1+n2+1)/2;
    int low=0; int high = n1;
    int n = n1+n2;

    while (low<=high) {
        int mid1 =(low+high)/2;
        int mid2 = left - mid1;
        int l1=INT_MIN; int l2 = INT_MIN;
        int r1=INT_MAX; int r2=INT_MAX;

        if (mid1<n1) r1 = vec1[mid1];
        if (mid2<n2) r2 = vec2[mid2];

        if (mid1-1 >=0 ) l1 = vec1[mid1-1];
        if (mid2-1 >=0 ) l2 = vec2[mid2-1];

        if (l1<r2 && l2<r1) {
            if (n%2==1) {
                return max(l1,l2);
            }
            return ((double)((max(l1,l2)+min(r1,r2))/2.0));
        }else if (l1>r2) {
            high=mid1-1;
        }else {
            low=mid1+1;
        }
    }

    return 0;
}

int main(){
    vector<int> vec1 = {1,3,5,7,9};
    vector<int> vec2 ={2,3,4,8,10};

    // cout<<findMedian_Brute(vec1,vec2);
    // cout<<findMedian_Better(vec1,vec2);
    cout<<findMedian_BS(vec1,vec2);
}