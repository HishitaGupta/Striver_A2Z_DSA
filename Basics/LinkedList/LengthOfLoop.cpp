
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;


public:
    Node (int data,Node* next) {
        this->data = data;
        this->next =next;
    }

    Node (int data) {
        this->data = data;
        this->next =nullptr;
    }

};

Node* convertToLL(vector<int> arr) {
    Node* head = new Node (arr[0]);
    Node* mover = head;

    for (int i=1;i<arr.size();i++) {
        Node* temp =new Node(arr[i]);
        mover->next = temp;
        mover = temp;

    }

    mover->next=head;

    return head;
}
int lengthOfLoop_brute(Node* head){
    Node* temp=head;
    map<Node*,int> mpp;
    int count=1;


    while(temp!=NULL){
         if (mpp.find(temp)!= mpp.end()) {
            return count-mpp[temp];
        }
        mpp[temp]=count;
        count++;
        temp=temp->next;
    }

    return 0;

}


int LengthOfLoop_Optimal(Node* head) {
    Node * slow=head; Node* fast=head;


    while (fast!=NULL && fast->next != NULL ) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            int count=1;
            fast=fast->next;
            while (fast!=slow) {
                fast=fast->next;
                count++;
            }
            return count;
        }
    }

    return 0;
}




int main() {

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head =convertToLL(arr);
    // cout<<lengthOfLoop_brute(head);
    cout<<LengthOfLoop_Optimal(head);





}