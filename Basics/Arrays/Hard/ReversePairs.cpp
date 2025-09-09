#include <bits/stdc++.h>
using namespace std;

// void merge(vector<int>&vec,int low,int mid,int high) {
//
//     int left=low;
//     int right=mid+1;
//     vector<int> temp;
//     while (left<=mid && right<=high) {
//         if (vec[left]>=vec[right]) {
//             temp.push_back(vec[right]);
//             right++;
//
//         }else {
//             temp.push_back(vec[left]);
//             left++;
//         }
//     }
//
//     while (left<=mid) {
//         temp.push_back(vec[left++]);
//     }
//
//     while (right<=high) {
//         temp.push_back(vec[right++]);
//     }
//
//     for (int i=low;i<=high;i++) {
//         vec[i]=temp[i-low];
//     }
//
//
// }
//
// int reversePairsCount(vector<int>&vec,int low,int mid,int high) {
//     int left=low;
//     int right=mid+1;
//     int count=0;
//
//     while (left<=mid ) {
//         while(right<=high && vec[left]> 2*vec[right]) {
//
//             right++;
//         }
//         count+=(right-(mid+1));
//         left++;
//     }
//     return count;
// }
//
// int mergeSort(vector <int> &vec,int low,int high) {
//     int cnt=0;
//     if (low>=high) return cnt;
//
//     int mid =((low+high)/2);
//
//
//     cnt+=mergeSort(vec,low,mid);
//     cnt+=mergeSort(vec,mid+1,high);
//     cnt+=reversePairsCount(vec,low,mid,high);
//     merge(vec,low,mid,high);
//
//     return cnt;
//
// }
//
// void reversePairsOptimal(vector<int>&vec) {
//     int n= mergeSort(vec,0,vec.size()-1);
//     cout<<n;
// }
//
// void reversePairsBrute(vector<int>& vec) {
//     int count = 0;
//     for (int i = 0; i < vec.size(); i++) {
//         for (int j = i + 1; j < vec.size(); j++) {
//             if (vec[i] > 2 * vec[j]) {
//                 cout << "Pairs: (" << vec[i] << ", " << vec[j] << ")\n";
//                 count++;
//             }
//         }
//     }
//     cout << "Number of pairs: " << count << endl;
// }

// ------------------------------------------------------------------------

int merge(vector<int>& vec, int low, int mid, int high) {
    int count = 0;
    int j = mid + 1;

    // 🔹 Count reverse pairs
    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)vec[i] > 2LL * vec[j]) {
            j++;
        }
        count += (j - (mid + 1)); //For each i (element in the left half),
       // we advance j as far as possible in the right half until the condition fails.
       // (Remember: the right half is sorted!)

        //When the while loop stops, all indices in the right half from mid+1 up to j-1 are valid partners for this i.
    }

    // 🔹 Standard merge process
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (vec[left] <= vec[right]) {
            temp.push_back(vec[left++]);
        } else {
            temp.push_back(vec[right++]);
        }
    }
    while (left <= mid) temp.push_back(vec[left++]);
    while (right <= high) temp.push_back(vec[right++]);

    for (int i = low; i <= high; i++) {
        vec[i] = temp[i - low];
    }

    return count;
}


int mergeSort (vector<int>&vec, int low, int high) {
    int count =0;

    if (low>=high) {
        return count;
    }

    int mid = (low+high)/2;

    count += mergeSort (vec, low, mid);
    count+= mergeSort (vec, mid+1, high);

    count += merge(vec, low, mid ,high);

    return count;
}


void reversePairsOptimal(vector<int> vec) {
    int n = vec.size();
    int count = mergeSort(vec, 0, n-1);
    cout<<count;
}



int main() {
    vector<int> vec ={5,3,4,2,1};
    reversePairsOptimal(vec); //log n * (n+n) - 2nlogn sc- o(n)
    // reversePairs(vec);
}