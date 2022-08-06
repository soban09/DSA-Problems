#include<iostream>
#include<queue>
using namespace std;

class BinaryTree{
    public :
        int data;
        BinaryTree *left;
        BinaryTree *right;
        
        BinaryTree(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~BinaryTree(){
            delete left;
            delete right;
        }
};

static int flag=0;

BinaryTree* takeInputBetter(){
    
    int rootData;
    cout<<"Enter data : "<<endl;
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }
    
    BinaryTree *root = new BinaryTree(rootData);
    queue <BinaryTree*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BinaryTree *front = pendingNodes.front();
        pendingNodes.pop();

        // cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;

        if(leftChildData != -1){
            BinaryTree *leftChild = new BinaryTree(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        
        // cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;

        if(rightChildData != -1){
            BinaryTree *rightChild = new BinaryTree(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        } 
    }
    return root;
}

void printBetter(BinaryTree *root){
    
    if(root == NULL){
        return;
    }

    queue <BinaryTree*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        BinaryTree *front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<" : ";
        if(front->left !=NULL){
            cout<<"L="<<front->left->data<<" ";
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R="<<front->right->data<<" ";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

bool isCompleteBT(BinaryTree* root){
        queue<BinaryTree*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            
            for(int i=0; i<sz; i++){
                auto front = q.front();
                q.pop();
                
                if(front==NULL){
                    while(!q.empty()){
                        if(q.front()!=NULL)
                            return false;
                        q.pop();
                    }
                    return true;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }

int main(){
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTree *root = takeInputBetter();
    printBetter(root);
    isCompleteBT(root) ? cout<<"Yes" : cout<<"No";

return 0;
}