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

Node* reverse(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp!=nullptr) {
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

Node* Add1ToLLNumber(Node* head) {


    head = reverse(head);
    int carry =1;
    Node* temp=head;

    while (temp!=nullptr) {
        if (temp->data + carry==10) {
            temp->data = 0;
            carry=1;
        }else {
            temp->data = temp->data+carry;
            carry=0;
            break;
        }
        temp= temp->next;
    }

    head = reverse(head);

    if (temp==nullptr && carry==1) {
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }

    return head;
}

int returnCarry(Node* temp) {
    if (temp==NULL) {
        return 1;
    }
    int carry = returnCarry(temp->next);
    temp->data = temp->data+ carry;
    if (temp->data ==10) {
        temp->data = 0;
        return 1; //carry
    }

    return 0;
}

Node* add1ToLLNumber_Optimal(Node* head) {

    int carry = returnCarry(head);

    if (carry==1) {
        Node* newHead= new Node(1);
        newHead->next = head;
        return newHead;
    }

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

    vector<int> arr = {9,9,9,9};
    Node* head =convertToLL(arr);
    // head = Add1ToLLNumber_Brute(head);
    head = add1ToLLNumber_Optimal(head);


    traverseLL(head);


}