#include<iostream>
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

int count(Node *a, Node *b){
    int c=0;
    while(a!=NULL && b!=NULL){
        if(a->data==b->data){
            c++;
            a=a->next;
            b=b->next;
        }
        else break;
    }
    return c;
}

int maxPalindrome(Node *head)
{
    if(head==NULL) return 0;
    if(head->next==NULL) return 1;
    
    Node *curr=head, *prv=NULL;
    int ans=0;
    
    while(curr!=NULL){
        Node *nxt = curr->next;
        curr->next = prv;
        
        ans=max(ans, 2*count(prv, nxt)+1);
        ans=max(ans, 2*count(curr, nxt));
        
        prv=curr;
        curr=nxt;
    }
    return ans;
}

int main(){
    Node *head = input();
    print(head);


    return 0;
}