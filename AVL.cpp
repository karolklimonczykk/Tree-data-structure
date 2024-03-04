#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node // node structure
{
    float data;
    node* left;
    node* right;
};

class BinarySearchTree // binary search tree class
{
    node* root;
    node* findMin(node*);
    node* findMax(node*);
    void insert(node*, float);
    void destroyTree(node*);
    void inOrder(node*);
    void preOrder(node*);
    void postOrder(node*);
    void levelOrder(node*);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(float);
    void destroyTree();
    void display();
    node* getRoot();
};

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    destroyTree();
}

void BinarySearchTree::insert(float key) // insert function to insert a node in the tree
{
    if (root != NULL)
    {
        insert(root, key);
    }
    else
    {
        root = new node;
        root->data = key;
        root->left = NULL;
        root->right = NULL;
    }
}

void BinarySearchTree::insert(node* leaf, float key)
{
    if (key < leaf->data)
    {
        if (leaf->left != NULL)
        {
            insert(leaf->left, key);
        }
        else
        {
            leaf->left = new node;
            leaf->left->data = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else
    {
        if (leaf->right != NULL)
        {
            insert(leaf->right, key);
        }
        else
        {
            leaf->right = new node;
            leaf->right->data = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

node* BinarySearchTree::findMin(node* t)
{
    if (t == NULL)
        return t;
    else if (t->left == NULL)
        return t;
    else return findMin(t->left);
}

node* BinarySearchTree::findMax(node* t)
{
    if (t == NULL)
        return t;
    else if (t->right == NULL)
        return t;
    else return findMax(t->right);
}

void BinarySearchTree::destroyTree()
{
    destroyTree(root);
}

void BinarySearchTree::destroyTree(node* leaf)
{
    if (leaf != NULL)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
    }
    delete leaf;
}

void BinarySearchTree::inOrder(node* t)
{
    if (t != NULL)
    {
        inOrder(t->left);
        cout << t->data << " ";
        inOrder(t->right);
    }
}

void BinarySearchTree::preOrder(node* t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

void BinarySearchTree::postOrder(node* t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
}

void BinarySearchTree::display()
{
    cout << "preOrder: ";
    preOrder(root);
    cout << "\ninOrder: ";
    inOrder(root);
    cout << "\npostOrder: ";
    postOrder(root);
    cout << "\nlevelOrder: ";
    levelOrder(root);
}

void BinarySearchTree::levelOrder(node* t)
{
    if (t != NULL)
    {
        queue<node*> q;
        // push root node into the queue
        q.push(t);
        // pop root node, push its left and right child nodes into the queue.
        // Exit the loop when the queue is empty.
        while (!q.empty())
        {
            node* current = q.front();
            cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            q.pop(); // remove this element from the front
        }
    }
}

node* BinarySearchTree::getRoot()
{
    return root;
}

int positiveCount = 0;
int negativeCount = 0;
void Calculate(node* root)
{
    if (root != nullptr)
    {
        if (root->data > 0)
        {
            positiveCount++;
        }
        else if (root->data < 0)
        {
            negativeCount++;
        }
        Calculate(root->left);
        Calculate(root->right);
    }
}

float sum = 0.0;
float SumOfElements(node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    sum += root->data;
    SumOfElements(root->left);
    SumOfElements(root->right);
}

int main()
{
    BinarySearchTree* tree = new BinarySearchTree();
    float num;

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> num;
        tree->insert(num);
    }

    Calculate(tree->getRoot());
    SumOfElements(tree->getRoot());
    tree->display();
    cout << endl;

    cout << "Number of positive elements: " << positiveCount << endl;
    cout << "Number of negative elements: " << negativeCount << endl;
    cout << "Sum of all elements: " << sum << endl;
    delete tree;

    return 0;
}
