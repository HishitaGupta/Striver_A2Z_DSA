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

Node* ReturnStartOfLoop_brute(Node* head){
    Node* temp=head;
    map<Node*,int> mpp;

    while(temp!=NULL){
        if (mpp.find(temp)!= mpp.end()) {
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }

    return NULL;

}


bool ReturnStartOfLoop_Optimal(Node* head) {
    Node * slow=head; Node* fast=head;

    while (fast!=NULL && fast->next != NULL ) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            slow=head;
            while (slow!=fast) {
                slow=slow->next;
                fast=fast->next;
            }
            return slow; //start
        }
    }

    return NULL;
}




int main() {

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head =convertToLL(arr);
    cout<<ReturnStartOfLoop_brute(head);




}