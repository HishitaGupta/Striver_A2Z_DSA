
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

Node* deleteFromBackBrute(int n, Node* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    int length =0;

    while (temp != NULL) {
        temp=temp->next;
        length++;
    }

    temp=head;
    if (length == n) {
        Node* newHead =head->next;
        delete (head);
        return newHead;

    }
    int distance = length- n-1;

    while (distance>0) {

        temp=temp->next;
        distance--;

    }
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;

    delete(deleteNode);

    return head;
}


Node* deleteFromBack_Optimal(int n, Node* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* fast= head;
    Node* slow=head;

    for (int i=0;i<n;i++) {
        fast= fast->next;
    }

    while (fast->next != NULL) {
        fast=fast->next;
        slow=slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;

}




void traverseLL(Node* head) {
    Node* temp=head;

    while (temp!= NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}


int main() {

    vector<int> arr = {1,2,3,4,5,};
    Node* head =convertToLL(arr);
    // head=deleteFromBackBrute(1,head);
    head=deleteFromBack_Optimal(1,head);


    traverseLL(head);


}