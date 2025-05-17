#include <bits/stdc++.h>
using namespace std;

// Brute force approach to remove duplicates from sorted array
//int removeDuplicates(int* arr, int n) {
//    set<int> s;
//    for(int i = 0; i < n; i++) {
//        s.insert(arr[i]);
//    }
//
//    int index = 0;
//    for(auto it : s) {
//        arr[index++] = it;
//    }
//
//    return index; // new size
//}

int removeDuplicates(int *arr,int n){
	
	int i=0;
	
	for(int j=i;j<n;j++){
		if(arr[i]!=arr[j]){
			arr[i+1]= arr[j];
			i++;
		}
	}
	return (i+1); 
}

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newSize = removeDuplicates(arr, n);

    cout << "After removing duplicates:\n";
    for(int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

