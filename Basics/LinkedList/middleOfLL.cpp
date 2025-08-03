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

    return head;
}

int middleOfLL(Node* head) {
    Node* temp= head;

    int count=0;

    while (temp!=nullptr){
        count++;
        temp=temp->next;
    }

    int middleNode = (count/2)+1;

    temp=head;

    while (temp!=NULL) {
        middleNode--;
       if (middleNode==0) {
           break;
       }
        temp=temp->next;
    }

    return temp->data;
}


int middleOfLL_Optimal(Node* head) {
    Node* slow= head;
    Node* fast =head;

    while (fast!=NULL && fast->next!=NULL) {
        slow= slow->next;
        fast = fast->next->next;
    }

    return slow;
}


int main() {

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head =convertToLL(arr);

    // cout<<middleOfLL(head);
    cout<<middleOfLL_Optimal(head);

}