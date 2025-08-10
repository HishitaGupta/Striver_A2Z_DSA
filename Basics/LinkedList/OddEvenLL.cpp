
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

Node* oddEvenLL_Brute(Node* head) {

    if (head==NULL || head->next==NULL) return head;
    Node* temp=head;
    vector<int> vec;

    while (temp!=NULL && temp->next != NULL) {
        vec.push_back(temp->data);
        temp=temp->next->next;
    }

    if (temp) vec.push_back(temp->data);

    temp=head->next;

    while (temp!=NULL && temp->next!=NULL) {
        vec.push_back(temp->data);
        temp=temp->next->next;
    }

    if (temp) vec.push_back(temp->data);

    temp=head; int i=0;

    while (temp!=NULL && i < vec.size()) {
        temp->data = vec[i];
        temp=temp->next;
        i++;
    }

    return head;
}

Node* oddEvenLL_Optimal(Node* head) {
    if (head==NULL || head->next==NULL) return head;
    Node* odd= head;
    Node* even=head->next;
    Node* evenHead=head->next;

    while (even->next!=NULL && even!=NULL) {
        odd->next=even->next;
        odd= odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenHead;

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

    vector<int> arr = {1,2,3,4,5,6};
    Node* head =convertToLL(arr);
     // head =oddEvenLL_Brute(head);
     head =oddEvenLL_Optimal(head);

    traverseLL(head);


}