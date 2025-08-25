
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


Node* sortLL_Brute(Node* head) {
    vector<int>vec;

    Node* temp= head;

    while (temp!=NULL) {
        vec.push_back(temp->data);
        temp=temp->next;
    }

    sort(vec.begin(),vec.end());

    temp=head;

   for (int i=0;i<vec.size();i++) {
       temp->data = vec[i];
       temp=temp->next;
   }

    return head;

}

Node* findMiddle(Node* head) {
    Node* fast = head->next; //so that middle stops at first midle element in case of even elements
    Node* slow=head;

    while (fast!=NULL && fast->next!=NULL) {
        fast= fast->next->next;
        slow=slow->next;
    }

    return slow;
}

Node* merge(Node* left , Node* right) {
   Node* dummyNode = new Node(-1);
    Node* temp= dummyNode;

    while (left!=NULL && right!=NULL) {
        if (left->data <= right->data) {
            temp->next = left;
            left=left->next;
        }else {
            temp->next = right;
            right = right->next;
        }
        temp= temp->next;
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (left != nullptr) {
        temp->next = left;
    } else {
        temp->next = right;
    }

    return dummyNode->next;
}


Node* sortLL_Optimal(Node* head) {
    if (head==NULL || head->next==NULL) {
        return head;
    }

    //find middle
    Node* middleNode = findMiddle(head);

    //divide into two halves
    Node* right = middleNode->next;
    middleNode->next = NULL;
    Node* left = head;


    //call recursive function
    left = sortLL_Optimal(left);
    right = sortLL_Optimal(right);

    //merge The sorted lists
   return merge(left,right);
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

    vector<int> arr = {5,4,3,2,1};
    Node* head =convertToLL(arr);
    // head=  sortLL_Brute(head);
    head=  sortLL_Optimal(head);




    traverseLL(head);


}