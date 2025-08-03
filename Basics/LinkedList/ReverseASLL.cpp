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

void traverseLL(Node* head) {
    Node* temp=head;

    while (temp!= NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

Node* reverseLL_Brute(Node* head) {
    Node* temp = head;
    stack<int> st;

    while (temp!=nullptr) {
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;

    while (temp!=NULL) {
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

Node* reverseLL_Optimal(Node* head) {
    Node* temp=head; Node* prev= NULL;

    while (temp!=NULL) {
        Node* next = temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }

    return prev;

}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};

    Node* head =convertToLL(arr);
    // head = reverseLL_Brute(head);
    head = reverseLL_Optimal(head);

    traverseLL(head);
}