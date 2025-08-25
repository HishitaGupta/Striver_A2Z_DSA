
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

Node* deleteTheMiddleNode_Brute(Node* head) { // incase of even delte the second middle element
    if (head==NULL || head->next== NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;

    int count=0;

    while (temp != NULL) {
        temp=temp->next;
        count++;
    }


    int n = count/2;



    if (n==0) {
        Node* newHead= head->next;
        delete head;
        return newHead;
    }

    temp=head;
    while ( temp !=NULL) {
        n--;
        if (n==0) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            break;

        }
        temp=temp->next;
    }

    return head;
}

Node* deleteMiddleNode_Optimal(Node* head) {
    Node* slow= head;
    Node* fast = head->next->next;


    while (fast!=NULL && fast->next!=NULL) {
        fast= fast->next->next;
        slow=slow->next;
    }

    slow->next = slow->next->next;

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
    // head=  deleteTheMiddleNode_Brute(head);
    head=  deleteMiddleNode_Optimal(head);


    traverseLL(head);


}