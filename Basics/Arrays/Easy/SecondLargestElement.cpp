  
  //Second Largest element
  
  #include<bits/stdc++.h>
  using namespace std;
  
  
  //Brute Force
//  void secondLargest(int arr[],int n){
//  	
//  	sort(arr,arr+n);
//  	for(int i=0;i<n;i++){
//  		cout<<arr[i]<<" ";
//	  }
//	  
//	int largest = arr[n-1];
//	int secondLargest;
//	  
//	for(int i=n-1;i>0;i--){
//			
//		if(largest!=arr[i]){
//			
//			secondLargest=arr[i];
//			cout<<"Second Largest:"<<secondLargest;
//			break;
//		}
//	}
// 	
//}
  
//Better Approach
//void secondLargest(int arr[],int n){
//	int largest=arr[0];
//	
//	for(int i=0;i<n;i++){
//		if(largest<arr[i]){
//			largest=arr[i];
//		}
//	}
//	
//	cout<<"Largest:"<<largest<<endl;
//	
//	int secondLargest = -1;
//	
//	for(int i=0;i<n;i++){
//		if(secondLargest<arr[i] && arr[i]<largest){
//			secondLargest = arr[i];
//		}
//	}
//	
//	cout<<"SecondLargest:"<<secondLargest;
//}
  
//Optimal Approach

void secondLargest(int arr[],int n){
	
	int largest = arr[0];
	int secondLargest = -1;
	
	for(int i=1;i<n;i++){
		
		if(arr[i]> largest){
			secondLargest = largest;
			largest = arr[i];
		}else if(arr[i] < largest && arr[i]>secondLargest){
			secondLargest = arr[i];
		}
	}
	
	cout<<"SecondLargest:"<<secondLargest;
}
 
  

  
int main(){
	
	int n;
	
	cout<<"Enter length of array:";
	cin>>n;
	
	int arr[n];
	
	cout<<"Enter array elements:";
	
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	secondLargest(arr,n);
}
