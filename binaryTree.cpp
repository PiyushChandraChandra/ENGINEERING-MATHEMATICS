#include<iostream>
using namespace std;

class Node 
{ 
    public:
    int key; 
    Node *left, *right; 
    int height;
    Node(int item = 0) 
    { 
        key = item; 
        left = right = NULL; 
    } 
};
class binaryTree
{
    protected:
    int data;
    Node *root;
    public:

    binaryTree()
    {
        root = NULL;
    }

    void printPostorder(Node *node) 
    { 
    if (node == NULL) 
         return; 
  
    printPostorder(node->left); 

    printPostorder(node->right); 
  
    cout << node->key << " ";
    }  

    void printInorder(Node *node) 
    { 
        if (node == NULL) 
         return; 
  
        printInorder(node->left); 

    printInorder(node->right); 
  
    cout << node->key << " ";
    }   
    void printPreorder(Node *node) 
    { 
        if (node == NULL) 
         return; 
  
        printPreorder(node->left); 

        printPreorder(node->right); 
    
        cout << node->key << " ";
    }   

virtual int height(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lDepth = height(node->left);  
        int rDepth = height(node->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  

};


class binarySearchTree : public binaryTree
{


int minValue(Node *root) 
    { 
        int minv = root->key; 
        while (root->left != NULL) 
        { 
            minv = root->left->key; 
            root = root->left; 
        } 
        return minv; 
    } 

public:



Node* insert(Node *root, int key) 
{ 
    if (root == NULL) 
    { 
        root = new Node(key); 
        return root; 
    } 
  
    if (key < root->key) 
        root->left  = insert(root->left, key); 
    else if (key > root->key) 
        root->right = insert(root->right, key); 

    return root;   
  
} 



Node* deleteTree(Node *root, int key) 
    { 
        if (root == NULL)  return root; 
  
        if (key < root->key) 
            root->left = deleteTree(root->left, key); 
        else if (key > root->key) 
            root->right = deleteTree(root->right, key); 

        else
        { 
            if (root->left == NULL) 
                return root->right; 
            else if (root->right == NULL) 
                return root->left; 
            root->key = minValue(root->right); 

            root->right = deleteTree(root->right, root->key); 
        } 
  
        return root; 
    } 


    void deleteKey(int key) 
    { 
        this->root = deleteTree(this->root, key); 
    } 

    void insert(int key) 
    { 
        this->root = insert(this->root, key); 
    } 



};


class avlTree : public binarySearchTree
{
    int height;

        
    int max(int a, int b) 
    { 
        return (a > b) ? a : b; 
    } 

    Node *rightRotate(Node *y)
     { 
        Node *x = y->left; 
        Node *T2 = x->right; 
  
        x->right = y; 
        y->left = T2; 
  
    
        y->height = max(binaryTree::height(y->left),binaryTree::height(y->right)) + 1; 
        x->height = max(binaryTree::height(x->left),binaryTree::height(x->right)) + 1; 
  

        return x; 
    } 

    Node *leftRotate(Node *x) 
       { 
        Node *y = x->right; 
        Node *T2 = x->left; 
  
        y->left = y; 
        x->right = T2; 
  
    
        y->height = max(binaryTree::height(y->left),binaryTree::height(y->right)) + 1; 
        x->height = max(binaryTree::height(x->left),binaryTree::height(x->right)) + 1; 
  

        return x; 
    } 

int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return binaryTree::height(N->left) - binaryTree::height(N->right);  
} 

Node* insert(Node* node, int key) 
{
    binarySearchTree::insert(node,key);
    this->height = 1 + max(binaryTree::height(node->left),binaryTree::height(node->right)); 

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node); 
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node); 
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
     if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  

    return node;
}
