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

BinaryTree *BuildBST(int *inorder, int s, int e){
    if(s==e){
        BinaryTree *root = new BinaryTree(inorder[s]);
        return root;
    }

    int mid = (s+e)/2;
    BinaryTree *root = new BinaryTree(inorder[mid]);
    root->left = BuildBST(inorder, s, mid-1);
    root->right = BuildBST(inorder, mid+1, e);
    return root;
}

int main(){
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTree *root = takeInputBetter();
    int pre[] = {1,2,3,4,5,6,7};
    BinaryTree *root = BuildBST(pre,0,6);
    printBetter(root);

return 0;
}