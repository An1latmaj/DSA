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

class Stack{
    public:
    Node* head=NULL;
    void push(int val){
        Node* n1 = new Node(val);
        Node* temp= head;
        if(head==NULL){
            head=n1;
            return;
        }
        n1->next=temp;
        head=n1;
    }
    void pop(){
        head=head->next;
    }
    int top(){
        return head->data;
    }
    bool empty(){
        if(head!=NULL) return false;
        else return true;
    }
};


int main(){
    Stack st;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        st.push(val);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    };
}