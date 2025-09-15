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


Node * Add2NumberToLL(Node* head1, Node* head2) {
    Node* dummy = new Node (-1);

    Node* t1 = head1; Node* t2 = head2;
    int carry =0; Node* curr= dummy;

    while (t1!=nullptr || t2!=nullptr) {
        int sum = carry;
        if (t1) sum += t1->data;
        if (t2) sum += t2->data;
        Node* newNode = new Node(sum%10);
        curr->next = newNode;
        carry = sum/10;

        if (t1) t1= t1->next;
        if (t2) t2= t2->next;
        curr= curr->next;
    }

    if (carry==1) {
        Node* newNode = new Node(carry);
        curr->next = newNode;

    }

    Node* head = dummy->next;
    // delete dummy , t1,t2,curr;
    return head;
}


void traverseLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main() {

    vector<int> arr1 = {2,4,6};
    vector<int> arr2 = {3,8,7};
    Node* head1 =convertToLL(arr1);
    Node* head2 =convertToLL(arr2);
    Node* head= Add2NumberToLL(head1, head2);



    traverseLL(head);


}