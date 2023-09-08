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
Node* Tail1;

void insertAtTail(Node* &tail,int value){
    if(tail==NULL){
        tail= new Node(value);
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
    map <Node*,bool> visited;

    while(temp->data==0){
        prev=temp;
        visited[temp]= true;
        temp=temp->next;

    }

    while(temp!=NULL) {
        if ( visited[temp] != true ) {
            if (temp->data == 0) {
                visited[temp]= true;
                prev->next = prev->next->next;
                temp->next = head;
                head = temp;
                temp = prev->next;

            } else if (temp->data == 2) {
                visited[temp]= true;
                prev->next = prev->next->next;
                temp->next = NULL;
                tail->next = temp;
                tail = tail->next;
                temp = prev->next;
            } else {
                visited[temp]= true;
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


Node* Merge(Node* &head1, Node* &head2){
    Node *temp1=head1,*temp2=head2,*head=temp1;
    Node* temp;
    while(temp1->data > temp2->data){
        temp=temp2;
        temp2=temp2->next;
        temp->next=temp1;
        head=temp;
    }

    while(temp2!=NULL){

        if(temp1->next->data > temp2->data){
            temp=temp2;

            temp2=temp2->next;
            temp->next=temp1->next;
            temp1->next=temp;

        }
        else if(temp1->next !=NULL){
            temp1=temp1->next;
        }
        else{
            temp1->next=temp2;
            return head;
        }

    }

    return head;
}


int main(){
    Node* head=NULL;
    Node* head1=NULL;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        if(i==0){
            insertAtTail(head,val);
            Tail=head;
        }
        else{
            insertAtTail(Tail,val);
        }
    }
    for(int i=0;i<n;i++){
        cin>>val;
        if(i==0){
            insertAtTail(head1,val);
            Tail1=head1;
        }
        else{
            insertAtTail(Tail1,val);
        }
    }
    head = Merge(head,head1);

    printLL(head);
//    Sort(head,Tail);

//    printLL(head);


}
