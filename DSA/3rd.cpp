#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data =data;
        left=NULL;
        right=NULL;
    }
};

//Traverse Tree - In-order traversal

void traversal(Node* root){
    if(root == NULL){
        return;
    }

    else{
        traversal(root->left);
        cout<<root->data<<" ";
        traversal(root->right);

    }
}

//Insertion in BST

Node* insert(Node* &root, int x){
    
    if(root == NULL){
        root = new Node(x);
    }
    else if (x >= root->data){
        root->right = insert(root->right, x);
    }
    else if (x < root->data){
        root->left = insert(root->left, x);
    }
    return root;
}

//Find number of nodes in longest path from root

int height(Node* root){

    if (root == NULL){
        return 0;
    }
    int left_subtree = 1+height(root->left);
    int right_subtree = 1+height(root->right);
    return max(left_subtree, right_subtree);
}

//Minimum data value found in the tree
//Check Only left part of BST becuase All nodes of the left subtree are lesser.
int minimum(Node* root){

    if (root->left == NULL){
        return root->data;
    }
    return min(minimum(root->left), root->data);
}

//Change a tree so that the roles of the left and right pointers are swapped at every node
void mirror(Node* &root){

    if(root == NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

//Search a value
void search(Node* root, int key, bool &present){

    if (root == NULL){
        return;
    }
    if(root->data == key){
        present = true;
    }
    else if (root->data > key){
        search(root->left, key, present);
    }
    else if (root->data <= key){
        search(root->right, key, present);
    }
}

int main(){
    Node *root = NULL;
    int n;
    cout<<"Enter the number of nodes you want to be inserted in the BST - "<<endl;
    cin>>n;

    for(int i=0; i<n; i++){
        int element;
        cout<<"Enter the data value to be inserted in "<<i<<" NODE: \n";
        cin>>element;
        insert(root, element);
    }
    cout<<"========================================="<<endl;
    
    cout<<"Displaying the elements of the BST: \n";
    traversal(root);

    cout<<"========================================="<<endl;

    cout<<"Height of the tree: "<<height(root)<<endl;

    cout<<"========================================="<<endl;

    cout<<"Minimum value in BST: "<<minimum(root)<<endl;
       
    cout<<"========================================="<<endl;

    int key;
    cout<<"Enter the data value to be search in BST: \n";
    cin>>key;
    bool present = false;
    search(root,key,present);
    if (present == true){
        cout<<"Key is present..."<<endl;
    }
    else{
        cout<<"opps  Key Not present.."<<endl;
    }
    return 0;
}
