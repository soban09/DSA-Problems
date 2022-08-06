//detecting, making and deleting a cycle n linked list-

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

bool detectCycle(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

Node* makeCycle(Node *head, int pos){
    Node *temp = head;
    Node *startNode;

    int count=1;
    while(temp->next != NULL){

        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = startNode;

    return head;
}

Node* deleteCycle(Node *head){
    Node *slow = head;
    Node *fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast!=slow);

    fast = head;

    while(fast->next != slow->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
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
    Node *head = input();
    print(head);

    cout<<detectCycle(head)<<endl;
    head = makeCycle(head,5);
    cout<<detectCycle(head)<<endl;
    head = deleteCycle(head);
    cout<<detectCycle(head)<<endl;

return 0;
}