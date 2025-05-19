#include<bits/stdc++.h>
using namespace std;

//Brute Force
void unionArrayBrute(int arr1[],int arr2[],int n1, int n2){
    set<int> st;
    for (int i=0;i<n1;i++) {
        st.insert(arr1[i]);
    }
    for (int i=0;i<n2;i++) {
        st.insert(arr2[i]);
    }
    int unionArr[st.size()];

    int i=0;
    for (auto it:st) {
        unionArr[i]=it;
        i++;
    }

    cout << "Union Array: ";
    for (int j = 0; j < st.size(); j++) {
        cout << unionArr[j] << " ";
    }
    cout << endl;

}

void unionArrayOptimal(vector <int> a,vector<int> b) {
    int n1= a.size();
    int n2=b.size();
    vector<int> unionArr;
    int i=0;
    int j=0;

    while (i<n1 && j<n2 ){
        if (a[i] <= b[j]) {
            if (unionArr.size()  ==0 || unionArr.back() != a[i]) {
                    unionArr.push_back(a[i]);
            }
            i++;
        }else {
            if (unionArr.size() ==0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (i<n1) {
        if (unionArr.size()==0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while (j<n2) {
        if (unionArr.size() ==0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    cout<<"Union:";
    for (auto it : unionArr) {
        cout<< it<<" ";
    }

}

int main() {

    int n1=5;
    int n2=6;

    int arr1[]={1,2,3,4,4};
    int arr2[]={1,2,4,5,6,8};

    vector<int> vec1 ={1,2,3,4,4};
    vector <int> vec2 ={1,2,4,5,6,8};

    // unionArrayBrute(arr1,arr2,n1,n2);
    unionArrayOptimal(vec1,vec2);


}
