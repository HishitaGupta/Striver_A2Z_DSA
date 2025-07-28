#include <bits/stdc++.h>
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

Node* removeHead (Node* head) {
    if (head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;

    return head;

}

Node* removeTail(Node* head) {

    if (head==NULL || head->next==NULL) {
       return NULL;
    }

    Node* temp = head;


    while (temp->next->next!=NULL) {
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;

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

Node* removeKthElement(Node* head,int k) {

    if (head==NULL) return head;

    if (k==1) return removeHead(head);

    Node* temp=head;
    int count=0;

    Node* prev =NULL;

    while (temp!=NULL) {
        count++;
        if (count==k){
            prev->next = prev->next->next;
            delete temp;
            break;
            }
        prev=temp;
        temp=temp->next;
    }

    return head;
}


Node* removeByValue(Node* head,int k) {

    if (head==NULL) return head;

    if (head->data==k) {
        Node* temp=head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp=head;

    Node* prev =NULL;

    while (temp!=NULL) {

        if (temp->data==k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    return head;
}

Node* insertHead(Node* head,int data) {
    Node* temp= new Node (data);
    temp->next = head;
    head=temp;

    return head;
}

Node* insertTail(Node* head,int data) {

    if (head==NULL) return new Node (data,head);

    Node* temp= head;

    while (temp->next != NULL) {
        temp=temp->next;
    }

    Node* Tail= new Node (data);
    temp->next = Tail;

    return head;
}

Node* insertAtKthPlace(Node* head, int k,int data) {

    if (head==NULL) {
        return new Node (data,head);
    }

    if (k==1) return insertHead(head,data);

    int count=0;
    Node* temp = head;
    Node* prev= NULL ;




    while (temp != NULL) {
        count++;
        if (count==k-1) {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next=newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

Node* insertBeforeValueK(Node* head, int value,int valueToInsert) {
    if (head==NULL) {
        return NULL;
    }

    if (head->data == value) {
        return new Node(valueToInsert,head);
    }

    Node* temp = head;

    while (temp->next != NULL) {
        if (temp->next->data ==value) {
            Node* newNode = new Node(valueToInsert,temp->next);
            temp->next=newNode;
            break;
        }
        temp= temp->next;
    }

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};

    Node* head =convertToLL(arr);
    head = removeHead(head);
    head=removeTail(head);
    head=removeKthElement(head,7);
    head=removeByValue(head,2);
    head=insertHead(head,1);
    head=insertTail(head,8);
    head=insertAtKthPlace(head,1,0);
    head=insertBeforeValueK(head,6,21);

    traverseLL(head);



}