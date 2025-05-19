#include <bits/stdc++.h>
using namespace std;

void intersectionArrayBrute(vector<int> a,vector<int> b) {

    vector <int> intArr ;
    int n1= a.size();
    int n2 = b.size();
    vector <int> visited(n1,0);

    for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++) {
            if (a[i]==b[j] && visited[j]==0) {
                intArr.push_back(a[i]);
                visited[j]=1;
                break;
            }
            if (b[j]>a[i]) break;
        }
    }

    for (auto it:intArr) {
        cout<<it<<" ";
    }


}

void intersectionArrayOptimal(vector <int> a,vector <int> b) {
    int i=0;
    int j=0;
    int n1= a. size();
    int n2= b.size();

    vector<int> intArr;

    while (i<n1 && j<n2) {
        if (a[i] < b[j]) {
            i++;
        }else if (b[j]<a[i]) {
            j++;
        }
        else{
            intArr.push_back(a[i]);
            i++;
            j++;
        }

    }

    cout<<"Intersection Array:";
    for (auto it:intArr) {
        cout<<it<<" ";
    }
}

int main() {

    int n1=5;
    int n2=6;

    int arr1[]={1,2,3,4,4};
    int arr2[]={1,2,4,5,6,8};

    vector<int> vec1 ={1,2,3,4,4};
    vector <int> vec2 ={1,2,4,5,6,8};


   intersectionArrayOptimal(vec1,vec2);


}
