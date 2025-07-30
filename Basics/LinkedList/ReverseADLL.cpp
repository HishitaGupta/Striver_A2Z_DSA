#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node (int data,Node*prev,Node*next){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    Node (int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }


};


Node* arrToDLL(vector<int> arr){
    if (arr.empty()) return nullptr;

    int n= arr.size();
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1;i<n;i++){
        Node* newNode = new Node(arr[i]);
        temp->next= newNode;
        newNode->prev = temp;
        temp=newNode;

    }
    return head;
}


void traverseDLL(Node* head){

    Node* temp= head;
    while(temp!= NULL){
        cout<<temp->data<<",";
        temp=temp->next;
    }

}

Node* reverseDLL_Brute(Node* head) {
    stack<int> st;

    Node* temp = head;

    while (temp!=NULL) {
        st.push(temp->data);
        temp= temp->next;
    }

    temp=head;

    while (temp!=NULL) {
       temp->data = st.top();
        st.pop();
        temp= temp->next;
    }

    return head;

}

Node* reverseDLL_Optimal(Node* head) {
    Node* temp= head; Node* newHead;

    while (temp != NULL) {
        Node* tempNode = temp->prev;
        temp->prev = temp->next;
        temp->next = tempNode;

        newHead = temp;

        temp=temp->prev;
    }

    return newHead;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head=arrToDLL(arr);
    // head=reverseDLL_Brute(head);

    head=reverseDLL_Optimal(head);

    traverseDLL(head);
}