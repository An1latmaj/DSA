#include <bits/stdc++.h>
using namespace std;
//creating a doubly linked list
class Node{
public:
    Node* prev;
    Node* nxt;
    int data;
    Node(int val){
        data=val;
        prev=NULL ;
        nxt=NULL ;
    }
};
//insertion for doubly linked list
void insertAtHead(Node* &nod,int val){
    if(nod==NULL){
        nod= new Node(val);
        return;
    }
    while(nod->prev!=NULL){
        nod=nod->prev;
    }
    Node* head=new Node(val);
    nod->prev=head;
    head->nxt=nod;
    nod=head;
}
void insertAtTail(Node*& node,int val){
    if(node==NULL){
        node= new Node(val);
        return;
    }
    Node* temp= node;
    Node* tail= new Node(val);
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }
    tail->prev=temp;
    temp->nxt=tail;
}
//deletion
void Del(Node* &head,int key){
    Node* node=head;

    while(node->nxt!=NULL){
        if(node->nxt->data==key){
            node->nxt=node->nxt->nxt;
            Node* temp=node;
            node=node->nxt;
            node->prev=temp;
            return;
        }
        node=node->nxt;
    }
    cout<<"Key not found";
}


int main(){
    Node* head=NULL;
    insertAtTail(head,10);
    insertAtTail(head,15);
    insertAtTail(head,25);
    insertAtHead(head,5);
    insertAtHead(head,10);
    Del(head,15);
    while(head!=NULL){
        cout<<head->data<<"  ";
        head=head->nxt;
    }


}