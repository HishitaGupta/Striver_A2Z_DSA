
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

Node* reverse_LL(Node* head) {
    if (head==NULL || head->next==NULL) return head;
    Node* prev=NULL;
    Node* next;

    while (head!=NULL) {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }

    return prev;
}

bool isPalindrome_Optimal(Node* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* reverseHead = reverse_LL(slow);

    // Step 3: Compare both halves
    Node* first = head;
    Node* second = reverseHead;
    bool isPalin = true;

    while (second != NULL) {
        if (first->data != second->data) {
            isPalin = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Restore list
    reverse_LL(reverseHead);

    return isPalin;
}


bool reorderedPowerOf2(int n) {

    vector<int> vec;
    int original = n;
    int i=0;

    while(n/10>=0){
        vec[i]=n%10;
        n=n/10;
        i++;
    }

    for (auto it:vec) {
        cout<<it;
    }

    int total=1;
   for (int j=1;j<vec.size();j++) {
       total= total*j;
   }

    cout<<total;

    int count=0;
    while(count<=total ){
        cout<<"Inside while";
        if (vec[0]!=0) {
            cout<<"Inside vec[0]";
            if(accumulate(vec.begin(),vec.end(),0)%2==0){
                next_permutation(vec.begin(),vec.end());
                count++;
            }else {
                return false;
            }
        }else {
            count++;
            next_permutation(vec.begin(),vec.end());
        }

    }

    return true;
}


int main() {

    vector<int> arr = {1,2,3,2,1};
    Node* head =convertToLL(arr);
    // cout<<isPalindrome_brute(head);
    // cout<<isPalindrome_Optimal(head);

    cout<<reorderedPowerOf2(22);

}