#include<bits/stdc++.h>
using namespace std;

// void searchInRotatedSortedArray(vector<int> vec, int target) {
//     int low=0, high=vec.size()-1;
//
//     while (low<=high) {
//         int mid = (low+high)/2;
//
//         if (vec[mid]==target) {
//             cout<<"Target found at "<<mid;
//             break;
//         }
//
//         if (vec[low]<= vec[mid]){ //left is sorted
//             if (vec[low]<=target && target <= vec[mid]) {
//                 high = mid-1;
//             }else {
//                 low=mid+1;
//             }
//         }
//
//         else { //right is sorted
//             if (vec[mid]<target && target<=vec[high]) {
//                 low=mid+1;
//             }else {
//                 high=mid-1;
//             }
//         }
//
//     }
// }

void searchInRotatedSortedDuplicateArray(vector<int> vec, int target) {
    int low=0, high=vec.size()-1;

    while (low<=high) {
        int mid = (low+high)/2;

        if (vec[mid]==target) {
            cout<<"Target found at "<<mid;
            break;
        }

        if (vec[low]==vec[mid] && vec[mid]==vec[high]) {
            low=low+1;
            high=high-1;
            continue;
        }

        if (vec[low]<= vec[mid]){ //left is sorted
            if (vec[low]<=target && target <= vec[mid]) {
                high = mid-1;
            }else {
                low=mid+1;
            }
        }

        else { //right is sorted
            if (vec[mid]<target && target<=vec[high]) {
                low=mid+1;
            }else {
                high=mid-1;
            }
        }

    }
}


int main() {
    vector<int> arr ={4,5,1,2,3,3,3};
    // searchInRotatedSortedArray(arr,3);
    searchInRotatedSortedDuplicateArray(arr,3); //with Duplicates
}