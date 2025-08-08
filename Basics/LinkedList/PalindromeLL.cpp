
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
bool isPalindrome_brute(Node* head){
    stack<int>st;
    Node* temp=head;

    while (temp!=NULL) {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL) {
        if (temp->data== st.top()) {
            st.pop();
            temp=temp->next;
        }else {
            return false;
        }
    }

    return true;
}

Node* reverse_LL()

bool isPalindrome_Optimal(Node* head) {
    Node* slow=head; Node* fast=head;

    while (fast->next!=NULL && fast->next->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* reverseHead = reverse_LL(slow->next);

}



int main() {

    vector<int> arr = {1,2,3,2,1 };
    Node* head =convertToLL(arr);
    cout<<isPalindrome_brute(head);
    // cout<<LengthOfLoop_Optimal(head);





}