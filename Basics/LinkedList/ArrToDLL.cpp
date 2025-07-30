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

Node* deleteHead(Node* head) {
    if (head==NULL || head->next) return nullptr;

    Node* prev=  head;

    head=head->next;
    head->prev=nullptr;

    prev->next = nullptr;

    delete prev;

    return head;
}

Node* deleteTail(Node* head) {

    if (head==NULL || head->next==NULL) return NULL;

    Node* temp =head;


    while (temp->next != NULL) {
        temp=temp->next;
    }

    Node* prev=temp->prev;

    prev->next = nullptr;
    temp->prev=nullptr;

    delete (temp);

    return head;
}

Node* deleteByPosition(Node* head,int k) {
    if (head==NULL) return NULL;

    int cnt=0;
    Node* kNode = head;

    while (kNode != NULL) {
        cnt++;
        if (cnt==k) break;
        kNode =kNode->next;
    }

    Node* prev = kNode->prev;
    Node* next = kNode->next;

    if (!prev && !next) {
        return NULL;
    }else if (!prev) {
        return deleteHead(head);
    }else if (!next) {
        return deleteTail(head);
    }

    prev->next = next;
    next->prev = prev;

   kNode->next= nullptr;
   kNode->prev= nullptr;

    delete kNode;

    return head;

}

Node* deleteByValue(Node* head,int value) {
    if (!head || !head->next) return NULL;

    Node* temp= head;

    while (temp != NULL) {
        if (temp->data == value) break;
        temp=temp->next;
    }

    if (!temp) return head;

    if (temp == head) {
        Node* newHead = head->next;
        if (newHead) newHead->prev = nullptr;
        delete head;
        return newHead;
    }

    Node* prev = temp->prev;
    Node* next = temp->next;

    if (prev) prev->next = next;
    if (next) next->prev=prev;

    temp->prev=nullptr;
    temp->next=nullptr;

    delete temp;

    return head;
}

void traverseDLL(Node* head){

    Node* temp= head;
    while(temp!= NULL){
        cout<<temp->data<<",";
        temp=temp->next;
    }

}

Node* insertHead(Node* head, int data) {
    if (!head) return new Node(data);

    Node* newHead = new Node(data);
    head->prev = newHead;
    newHead->next=head;

    return newHead;
}

Node* insertTail(Node* head, int data) {
    if (!head) return new Node(data);

    Node* newTail = new Node(data);
    Node* temp=head;

    while (temp->next != NULL) {
        temp=temp->next;
    }

    temp->next = newTail;
    newTail->prev= temp;

    return head;


}

Node* insertAtPosition(Node* head, int k,int value) {
    if (!head) return nullptr;

    if (k==1) return insertHead(head,value);

    Node* temp = head;

    int count=0;

    while (temp->next != NULL) {
        count++;
        if (count==k-1) {
            break;
        }
        temp= temp->next;
    }

    Node* newNode = new Node(value);

    Node* front = temp->next;

    temp->next = newNode;
    if (front) front->prev = newNode;

    newNode->prev = temp;
    newNode->next = front;

    return head;
}

Node* insertBeforeValue(Node* head, int k,int value) {
    if (!head) return nullptr;

    if (k==1) return insertHead(head,value);

    Node* temp = head;

    while (temp->next != NULL) {

        if (temp->data==k) {
            break;
        }
        temp= temp->next;
    }

    if (!temp) return NULL;

    Node* newNode = new Node(value);

    Node* prev = temp->prev;

    temp->prev = newNode;
    if (prev) prev->next = newNode;

    newNode->prev = prev;
    newNode->next = temp;

    return head;
}



int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head=arrToDLL(arr);
    // head=deleteHead(head);
    // head=deleteTail(head);
    // head=deleteByPosition(head,1);
    // head=deleteByValue(head,1);
    // head=insertHead(head,0);
    // head=insertTail(head,9);
    // head=insertAtPosition(head,9,100);
    head=insertBeforeValue(head,100,100);
    traverseDLL(head);

}