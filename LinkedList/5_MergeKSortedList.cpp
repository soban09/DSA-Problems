#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

Node* input(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    
    while(data != -1){
        Node *newnode = new Node(data);    
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;   
            tail = tail->next;  
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl; 
}



int main(){
    Node *head1 = input();
    Node *head2 = input();
    Node *head3 = input();
    print(head1);
    print(head2);
    print(head3);

    priority_queue<Node*> heap;
    heap.push(head1);
    heap.push(head2);
    heap.push(head3);

    auto t = heap.top();
    t=t->next;
    cout<<heap.top()->data<<endl;
    cout<<t->data<<endl;

    return 0;
}