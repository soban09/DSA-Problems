#include<bits/stdc++.h>
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

int MaxSumtoAnyNode(BinaryTree *root, int &res){
    if(root==NULL) return 0;

    int r = MaxSumtoAnyNode(root->right, res);
    int l = MaxSumtoAnyNode(root->left, res);

    int temp = max(max(l,r)+root->data, root->data);
    int ans = max(temp, root->data+l+r);
    res = max(ans, res);

    return temp;
}

int MaxSumleafToleaf(BinaryTree *root, int &res){
    if(root==NULL) return 0;

    int r = MaxSumleafToleaf(root->right, res);
    int l = MaxSumleafToleaf(root->left, res);

    if(root->left==NULL) return r+root->data;
    if(root->right==NULL) return l+root->data;

    int temp = max(l,r)+root->data;
    res = max(res, root->data+l+r);
    // res = max(ans, res);

    return res;
}

int main(){
    BinaryTree *root = takeInputBetter();
    // int res = INT_MIN;
    // int temp = MaxSumtoAnyNode(root, res);
    // cout<<res;

    int res1 = INT_MIN;
    int temp1 = MaxSumleafToleaf(root, res1);
    cout<<endl<<res1;
return 0;
}