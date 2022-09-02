#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class BinaryTree
{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTree()
    {
        delete left;
        delete right;
    }
};

BinaryTree *takeInputBetter()
{

    int rootData;
    cout << "Enter data : " << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTree *root = new BinaryTree(rootData);
    queue<BinaryTree *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTree *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;

        if (leftChildData != -1)
        {
            BinaryTree *leftChild = new BinaryTree(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;

        if (rightChildData != -1)
        {
            BinaryTree *rightChild = new BinaryTree(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printBetter(BinaryTree *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<BinaryTree *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTree *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << "L=" << front->left->data << " ";
        }
        if (front->right != NULL)
        {
            cout << "R=" << front->right->data << " ";
        }

        cout << endl;

        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
        }
    }
}

bool isLeaf(BinaryTree *root)
{
    return (root->right == NULL) && (root->left == NULL);
}

void leftBoundary(BinaryTree *root, vector<int> &v)
{
    // not root node, because it is already been added
    BinaryTree *tmp = root->left;
    while (tmp != NULL)
    {

        // not pushing leaf Node
        if (!isLeaf(tmp))
            v.push_back(tmp->data);
        if (tmp->left != NULL)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
}

void leafNodes(BinaryTree *root, vector<int> &v)
{
    if (root == NULL)
        return;
    if (isLeaf(root))
        v.push_back(root->data);

    leafNodes(root->left, v);
    leafNodes(root->right, v);
}

void rightBoundary(BinaryTree *root, vector<int> &v)
{
    // not root node, because it is already been added
    BinaryTree *tmp = root->right;
    vector<int> u;

    while (tmp != NULL)
    {

        // not pushing leaf Node
        if (!isLeaf(tmp))
            u.push_back(tmp->data);
        if (tmp->right != NULL)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    for (int i = u.size() - 1; i >= 0; i--)
        v.push_back(u[i]);
}

vector<int> boundary(BinaryTree *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    if (isLeaf(root))
        return ans;

    leftBoundary(root, ans);
    leafNodes(root, ans);
    rightBoundary(root, ans);

    return ans;
}

int main()
{

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTree *root = takeInputBetter();
    vector<int> bdry = boundary(root);
    for(auto a:bdry)
        cout<<a<<" ";
    return 0;
}