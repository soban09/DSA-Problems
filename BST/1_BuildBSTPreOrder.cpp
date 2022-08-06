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

BinaryTree *BuildBST(int *pre, int &i, int n, int upperBound){
    if(i==n || pre[i]>upperBound)
        return NULL;
    
    BinaryTree *root = new BinaryTree(pre[i++]);
    root->left = BuildBST(pre,i,n,root->data);
    root->right = BuildBST(pre,i,n,upperBound);

    return root;
}

int main(){
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTree *root = takeInputBetter();
    int pre[] = {40,30,80,35,100};
    int i=0;
    BinaryTree *root = BuildBST(pre,i,5,INT16_MAX);
    printBetter(root);

return 0;
}