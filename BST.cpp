#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class AVLTree {
public:
    class Node {
    public:
        T key;
        int height;
        Node* left;
        Node* right;
        Node(T k) {
            height = 1;
            key = k;
            left = NULL;
            right = NULL;
        }
    };
    Node* root = NULL;
    int n;

    // Insert a key into the AVL tree
    void insert(T x) {
        root = insertUtil(root, x);
    }

    // Remove a key from the AVL tree
    void remove(T x) {
        root = removeUtil(root, x);
    }

    // Search for a key in the AVL tree
    Node* search(T x) {
        return searchUtil(root, x);
    }

    // Perform inorder traversal of the AVL tree
    void inorder() {
        inorderUtil(root);
        cout << endl;
    }

    // Find the maximum element in the AVL tree
    int maxValue = 0;
    void MaxElement() {
        MaxElementUtil(root);
        cout << "Maximum element: " << maxValue << endl;
    }

    // Calculate the height of the AVL tree
    int maxHeight = 0;
    void TreeHeight() {
        TreeHeightUtil(root);
        cout << "Tree height: " << maxHeight << endl;
    }

    // Calculate the sum of even elements in the AVL tree
    int sumOfEven = 0;
    void SumOfEven() {
        SumOfEvenUtil(root);
        cout << "Sum of even elements: " << sumOfEven << endl;
    }

private:
    // Get the height of a node
    int height(Node* head) {
        if (head == NULL) return 0;
        return head->height;
    }

    // Right rotation
    Node* rightRotate(Node* head) {
        Node* newRoot = head->left;
        head->left = newRoot->right;
        newRoot->right = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
        return newRoot;
    }

    // Left rotation
    Node* leftRotate(Node* head) {
        Node* newRoot = head->right;
        head->right = newRoot->left;
        newRoot->left = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
        return newRoot;
    }

    // Inorder traversal utility function
    void inorderUtil(Node* head) {
        if (head == NULL) return;
        inorderUtil(head->left);
        cout << head->key << " ";
        inorderUtil(head->right);
    }

    // Utility function to insert a key into the AVL tree
    Node* insertUtil(Node* head, T x) {
        if (head == NULL) {
            n += 1;
            Node* temp = new Node(x);
            return temp;
        }
        if (x < head->key)
            head->left = insertUtil(head->left, x);
        else if (x > head->key)
            head->right = insertUtil(head->right, x);
        head->height = 1 + max(height(head->left), height(head->right));
        int balance = height(head->left) - height(head->right);
        if (balance > 1) {
            if (x < head->left->key)
                return rightRotate(head);
            else {
                head->left = leftRotate(head->left);
                return rightRotate(head);
            }
        }
        else if (balance < -1) {
            if (x > head->right->key)
                return leftRotate(head);
            else {
                head->right = rightRotate(head->right);
                return leftRotate(head);
            }
        }
        return head;
    }

    // Utility function to remove a key from the AVL tree
    Node* removeUtil(Node* head, T x) {
        if (head == NULL) return NULL;
        if (x < head->key) {
            head->left = removeUtil(head->left, x);
        }
        else if (x > head->key) {
            head->right = removeUtil(head->right, x);
        }
        else {
            Node* r = head->right;
            if (head->right == NULL) {
                Node* l = head->left;
                delete(head);
                head = l;
            }
            else if (head->left == NULL) {
                delete(head);
                head = r;
            }
            else {
                while (r->left != NULL) r = r->left;
                head->key = r->key;
                head->right = removeUtil(head->right, r->key);
            }
        }
        if (head == NULL) return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int balance = height(head->left) - height(head->right);
        if (balance > 1) {
            if (height(head->left) >= height(head->right))
                return rightRotate(head);
            else {
                head->left = leftRotate(head->left);
                return rightRotate(head);
            }
        }
        else if (balance < -1) {
            if (height(head->right) >= height(head->left))
                return leftRotate(head);
            else {
                head->right = rightRotate(head->right);
                return leftRotate(head);
            }
        }
        return head;
    }

    // Utility function to search for a key in the AVL tree
    Node* searchUtil(Node* head, T x) {
        if (head == NULL) return NULL;
        T k = head->key;
        if (k == x) return head;
        if (k > x) return searchUtil(head->left, x);
        if (k < x) return searchUtil(head->right, x);
    }

    // Utility function to find the maximum element in the AVL tree
    void MaxElementUtil(Node* head) {
        if (head == NULL) return;
        if (head->key > maxValue) {
            maxValue = head->key;
        }
        MaxElementUtil(head->left);
        MaxElementUtil(head->right);
    }

    // Utility function to calculate the height of the AVL tree
    void TreeHeightUtil(Node* head) {
        if (head == NULL) return;
        if (head->height > maxHeight) {
            maxHeight = head->height;
        }
        TreeHeightUtil(head->left);
        TreeHeightUtil(head->right);
    }

    // Utility function to calculate the sum of even elements in the AVL tree
    void SumOfEvenUtil(Node* head) {
        if (head == NULL) return;
        if (head->key % 2 == 0) {
            sumOfEven += head->key;
        }
        SumOfEvenUtil(head->left);
        SumOfEvenUtil(head->right);
    }
};

int main() {
    AVLTree<int> AVL_tree;
    int num;

    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> num;
        AVL_tree.insert(num);
    }

    AVL_tree.MaxElement();
    AVL_tree.TreeHeight();
    AVL_tree.SumOfEven();

    return 0;
}
