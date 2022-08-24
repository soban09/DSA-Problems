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

        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;

        if(leftChildData != -1){
            BinaryTree *leftChild = new BinaryTree(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        
        cout<<"Enter right child of "<<front->data<<endl;
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

BinaryTree* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE){
    
    //base case
    if(inS > inE){
        return NULL;
    }

    //recursive case
    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i=inS; i<=inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex-1;
    int lPreS = preS+1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex+1;
    int rInE = inE;
    int rPreS = lPreE+1;
    int rPreE = preE;

    BinaryTree *root = new BinaryTree(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
    
}

BinaryTree* buildTreeFromPreOrder(vector<int> &preorder, int sI, int lI){
    if(sI>lI){
        return NULL;
    }
    

    if(sI==lI){
        return new BinaryTree(preorder[sI]);
    }

    BinaryTree *root = new BinaryTree(preorder[sI]);

    int i=sI;
    int r = preorder[sI];
    BinaryTree *root = NULL;

//to find the element index greater than the left root childrens
    while(i<preorder.size() && r>=preorder[i]){
        i++;
    }
    root->left = buildTreeFromPreOrder(preorder, sI+1, i-1);
    root->right = buildTreeFromPreOrder(preorder, i, lI);

    return root;
}

BinaryTree* buildTree(int* in, int* pre, int size){
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
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
        }
        if(front->right != NULL){
            cout<<"R="<<front->right->data<<" ";
        }

        cout<<endl;

        if(front->left !=NULL){
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            pendingNodes.push(front->right);
        }
    }
}

int main(){

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    //4 2 5 1 8 6 9 3 7
    //1 2 4 5 3 6 8 9 7
    int in[]={4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[]={1, 2, 4, 5, 3, 6, 8, 9, 7};

    BinaryTree *root = buildTree(in, pre, 9);
    // BinaryTree *root = takeInputBetter();
    printBetter(root);
    delete root;
    

return 0;
}