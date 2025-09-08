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

Node* sortLL_Brute(Node* head) {

    Node* temp= head;
    int count0=0 , count1=0, count2=0;

    while (temp!=NULL) {
        if (temp->data==0) {
            count0++;
        }else if (temp->data == 1) {
            count1++;
        }else {
            count2++;
        }
        temp= temp->next;
    }

    temp = head;

    while (temp!=NULL) {
        if (count0 != 0) {
            temp->data = 0;
            count0--;
        }else if (count1 != 0) {
            temp->data =1;
            count1--;
        }else {
            temp->data = 2;
            count2--;
        }

        temp= temp->next;
    }

    return head;
}


Node* sortLL_Better(Node* head) {
    Node* zeroHead= new Node(-1);
    Node* oneHead= new Node(-1);
    Node* twoHead= new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data==0) {
            zero -> next = temp;
            zero = zero->next;
        }else if (temp->data ==1) {
            one -> next = temp;
            one  = one->next;
        }else {
            two -> next = temp;
            two = two->next;
        }
        temp=temp->next;
    }

    zero->next = oneHead-> next  ? oneHead-> next : twoHead->next ;
    one->next = twoHead -> next;
    two->next = NULL;

    Node* newHead =zeroHead -> next;

    delete zeroHead , oneHead , twoHead;

    return newHead;
}


int main(){
    vector<int> arr = {1,0,1,0,2,2,2,1,0,1,0,0,1};

    Node* head =convertToLL(arr);

    // head = sortLL_Brute(head);
    head = sortLL_Better(head);

    traverseLL(head);
}