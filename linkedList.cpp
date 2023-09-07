#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
Node* Tail;

void insertAtTail(Node* &tail,int value){
    if(tail==NULL){
        tail= new Node(value);
        Tail=tail;
        return;
    }
    Node* data = new Node(value);
    tail->next=data;
    tail=data;

}

void insertAtHead(Node* &head,int val){
    Node* n1 = new Node(val);
    Node* temp= head;
    if(head==NULL){
        head=n1;
        return;
    }
    n1->next=temp;
    head=n1;
}

void Delete(Node* &head,int val){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next->data==val){
            break;
        }
        temp=temp->next;
    }
    temp->next= temp->next->next;

}

void printLL(Node* &head){
    Node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=NULL);
    cout<<"NULL"<<endl;

}

void reverse(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    head=prev;
}

Node* Kreversal(Node* &head,int n){

    Node* curr=head;
    Node* prev=NULL;
    Node* next;
    int count=0;
    while(count<n && curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(curr!=NULL)
    head->next= Kreversal(curr,n);

    return prev;
}


void Sort(Node* &head, Node* &tail){
    Node* temp=head;
    Node* prev=NULL;
    map <Node*,bool> Check;
    while(temp->data==0){
        prev=temp;
        temp=temp->next;
        Check[temp]= true;
    }

    while(temp!=NULL) {
        if (Check[temp] == false) {
            if (temp->data == 0) {
                Check[temp]= true;
                prev->next = prev->next->next;
                temp->next = head;
                head = temp;
                temp = prev->next;

            } else if (temp->data == 2) {
                Check[temp]= true;
                prev->next = prev->next->next;
                temp->next = NULL;
                tail->next = temp;
                tail = tail->next;
                temp = prev->next;
            } else {
                Check[temp]= true;
                prev = temp;
                temp = temp->next;
            }
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }

}


int main(){
    Node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(Tail,2);
    insertAtTail(Tail,0);
    insertAtTail(Tail,2);
    insertAtTail(Tail,0);
    insertAtHead(head,1);
    insertAtTail(Tail,2);
    insertAtTail(Tail,1);

    printLL(head);
    Sort(head,Tail);

    printLL(head);


}