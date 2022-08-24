//calculating diameter of a binary tree
// complexity = n*h
//1st case = symmetrical tree => h = logn => complexity = nlogn
//2nd case = one sided tree => h = n => complexity = n*n

//but where is the problem?
//when we call height func on root it calls the height to its left and right
//when we call diameter func on root it calls height + diameter func on its left and right
//hence height func is being called several times within the layer of the tree
//thus we need to make pair class to return both height+diamter from the func

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

int height(BinaryTree *root){
    if(root == NULL){
        return 0;
    }

    return (1+ max(height(root->left), height(root->right)));
}

int diameter(BinaryTree *root){
    if(root = NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

pair<int, int> HeightDiameter(BinaryTree *root){
    if(root == NULL){
        pair <int, int> p;
        p.first = 0;    //first = height
        p.second = 0;   //second = diameter
        return p;
    }

    pair<int, int> leftAns = HeightDiameter(root->left);
    pair<int, int> rightAns = HeightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
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
    BinaryTree *root = takeInputBetter();

    pair<int, int> p = HeightDiameter(root);
    
    cout<<"Height :"<<p.first<<endl;
    cout<<"Diameter :"<<p.second<<endl;

return 0;
}