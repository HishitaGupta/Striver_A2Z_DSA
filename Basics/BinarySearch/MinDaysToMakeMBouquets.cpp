#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> bloomDays , int bloomDay , int numberOfBouquets,int adjacentFlowers) {
    int counter=0; int BouquetsFormed =0;

    for (int i=0;i<bloomDays.size();i++) {
        if (bloomDays[i]<=bloomDay) {
            counter+=1;
        }else {
            BouquetsFormed+=counter/adjacentFlowers;
            counter=0;
        }
    }

    BouquetsFormed+=counter/adjacentFlowers;

    if (BouquetsFormed>=numberOfBouquets) return true;
    else return false;
}

// int minDays(vector<int>bloomdays,int numberOfBouquets,int adjancentFlowers) {
//
//     if (bloomdays.size()<numberOfBouquets*adjancentFlowers) return -1;
//     int ans =INT_MAX;
//
//     for (int i=0;i<bloomdays.size();i++) {
//         if (possible(bloomdays,bloomdays[i],numberOfBouquets,adjancentFlowers)) {
//             ans = min(ans,bloomdays[i]);
//         }
//     }
//
//     return ans;
// }

int min(vector<int> vec) {
    int min = INT_MAX;
    for (int i=0;i<vec.size();i++) {
        if (vec[i]<min) {
            min=vec[i];
        }
    }
    return min;
}

int max(vector<int> vec) {
    int max = INT_MIN;
    for (int i=0;i<vec.size();i++) {
        if (vec[i]>max) {
            max=vec[i];
        }
    }
    return max;
}

int minDays_BS(vector<int>bloomdays,int numberOfBouquets,int adjancentFlowers) {

    if (bloomdays.size()<numberOfBouquets*adjancentFlowers) return -1;
    int ans =INT_MAX;

    int low = min(bloomdays);
    int high = max(bloomdays);

    while (low<=high) {
        int mid =(low+high)/2;

        if (possible(bloomdays,mid,numberOfBouquets,adjancentFlowers)) {
            ans = min(ans,mid);
            high=mid-1; // need minimum
        }else {
            low=mid+1;
        }
    }

    return ans;
}

bool isPossiblePractice(vector<int> bloomDays , int dayTaken , int numberOfBouquets , int adjancentFlowers) {
    int flowerCount =0; int bouquetsMade =0;
    for (int i=0;i<bloomDays.size();i++) {
        if (bloomDays[i]<= dayTaken ) {
            flowerCount++;
        }else {
            bouquetsMade+=flowerCount/adjancentFlowers;
            flowerCount=0;
        }
    }
    bouquetsMade+=flowerCount/adjancentFlowers;

    if (bouquetsMade>=numberOfBouquets) return  true;
    else return false;
}

int  minDaysRequired_Practice(vector<int> bloomDays , int numberOfBouquets , int adjancentFlowers) {
    int low = *min_element(bloomDays.begin(),bloomDays.end());
    int high = *max_element(bloomDays.begin(),bloomDays.end());
    int ans = INT_MAX;

    while (low<=high) {
        int mid = (low+high)/2;

        if (isPossiblePractice(bloomDays,mid,numberOfBouquets,adjancentFlowers)) {
            ans=min(ans,mid);
            high = mid-1;
        }else {
            low=mid+1;
        }
    }

    return ans;
}

int main() {
    vector<int> bloomDays = {7,7,7,7,13,11,12,7};
    int numberOfBouquets = 2;
    int adjancentFlowers =3;
    // cout<<minDays(bloomDays,numberOfBouquets,adjancentFlowers);
    cout<<minDays_BS(bloomDays,numberOfBouquets,adjancentFlowers);
    // cout<<minDaysRequired_Practice(bloomDays,numberOfBouquets,adjancentFlowers);
}