#include <bits/stdc++.h>
using namespace std;

// void checkRotationTimes(vector<int> vec) {
//     vector<int>newVec(vec);
//    sort(newVec.begin(),newVec.end());
//     int n=vec.size();
//     int d=1;
//
//     while (newVec[0]!= vec[0]) {
//         reverse(vec.begin(),vec.begin()+d);
//         reverse(vec.begin()+d,vec.begin()+n);
//         reverse(vec.begin(),vec.begin()+n);
//         d++;
//     }
//
//     cout<<d;
// }

// void checkRotationTimesBS(vector<int> vec) {
//     int low=0; int high = vec.size()-1;
//     int minNum = INT_MAX;
//     int minIndex=-1;
//
//     while (low<=high) {
//         int mid =(low+high)/2;
//
//         if (vec[low]<=vec[high]) {
//             minNum=min(minNum,vec[low]);
//             minIndex=low;
//             break;
//         }
//
//         if (vec[low]<vec[mid]) {
//             //left is sorted
//             minNum = min(minNum,vec[low]);
//             if (minNum==vec[low]) {
//                 minIndex = low;
//             }
//             low=mid+1;
//         }else {
//             minNum = min(minNum,vec[mid]);
//             if (minNum==vec[mid]) {
//                 minIndex = mid;
//             }
//             high=mid-1;
//         }
//     }
//
//     cout<<minIndex<<minNum;
//
// }
//
// void  checkRotationTimesBSDuplicates(vector<int> vec) {
//     int low=0; int high=vec.size()-1;
//     int minNum = INT_MAX;
//     int minIndex=-1;
//
//     while (low<=high) {
//         int mid = (low+high)/2;
//
//         if (vec[low]==vec[mid] && vec[mid]==vec[high]) { //if duplicates
//             low++; //skip duplicates
//             high--;
//             continue;
//         }
//
//         if (vec[low]<vec[high]) { //if segment is sorted
//             minIndex=low;
//             break;
//         }
//
//         if (vec[low]<=vec[mid]) {
//             //left is sorted
//             minNum = min(minNum,vec[low]);
//             if (minNum==vec[low]) {
//                 minIndex = low;
//             }
//             low=mid+1;
//         }else {
//             minNum = min(minNum,vec[mid]);
//             if (minNum==vec[mid]) {
//                 minIndex = mid;
//             }
//             high=mid;
//         }
//     }
//
//     cout<<minIndex;
//
// }




int main(){
    vector<int> vec ={1,1,1,1,1};
    // checkRotationTimes(vec);
    // checkRotationTimesBS(vec);
    // checkRotationTimesBSDuplicates(vec);
    // checkRotationTimes_Practice(vec);
}