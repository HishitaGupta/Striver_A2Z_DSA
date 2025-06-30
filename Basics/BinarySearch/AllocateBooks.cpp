#include <bits/stdc++.h>
using namespace std;

int numberOfStudents(vector<int> pages, int maxPages ) {
    int student=1;
    int pagesAllocated =0;
    for (int i=0;i<pages.size();i++) {
        if (pagesAllocated+pages[i] <= maxPages) {
            pagesAllocated=pagesAllocated+pages[i];
        }else {
            student++;
            pagesAllocated=pages[i];
        }
    }
    return student;
}

int minMaxPages_Simple(vector<int> pages , int studentNo) {
    int low = *max_element(pages.begin(),pages.end());
    int high = accumulate(pages.begin(),pages.end(),0);

    if (pages.size() < studentNo) return -1;

    for (int i=low;i<=high;i++) {
        if (numberOfStudents (pages,i)==studentNo) {
            return i;
        }
    }
    return -1;
}

int minMaxPages_BS(vector<int> pages , int studentNo) {
    int low = *max_element(pages.begin(),pages.end());
    int high = accumulate(pages.begin(),pages.end(),0);
    int ans =0;

    if (pages.size() < studentNo) return -1;

    while (low<=high) {
        int mid = (low+high)/2;
        int numberOfStudent = numberOfStudents(pages,mid);

        if (numberOfStudent ==studentNo) {
            ans= mid;
            high=mid-1; //to find min

        }else if (numberOfStudent> studentNo) {
            low=mid+1; // zada pages allot kro
        }else {
            high=mid-1; //kam pages allot kro
        }
    }


    return ans;
}

//min max pages alloted to student
// range -  max pages , sum of all pages
// i will find mid in this range and check how many students can be served with this pages number
//hihihahahah


int main() {
    vector<int> pages  = {25,46,28,49,24};
    int studentNo= 4;
    // cout<<minMaxPages_Simple(pages,studentNo);
    cout<<minMaxPages_BS(pages,studentNo);
}