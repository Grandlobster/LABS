#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    
    void insert(Node* root, int val) {
        if (root == nullptr) {
            cout << "Cannot insert into a null node" << endl;
            return;
        }
        
        if (root->data == val || root->data > val) {
            cout << "Invalid data value" << endl;
        } else {
            if (root->right == nullptr) {
                root->right = new Node(val);
                cout << "Value added to the right" << endl;
            } else {
                cout << "Right node is not null, cannot insert" << endl;
            }
        }
    }
    void minimum(Node* root){
        int no,i;
        cout<<"Enter no of nodes";
        cin>>no;
        if(root==nullptr){
            cout<<"Tree is empty";
            return;
        }
        Node* temp;
        Node* new_temp;
        temp=root;
        while(i<no){    
            if(temp->left>new_temp->left){
                temp->left=new_temp->left;
                new_temp->left=temp->left->left;
            }

        }
        
    }
};

int main() {
    Node ROOT(50);
    int no_nodes;
    cout << "Enter how many nodes: ";
    cin >> no_nodes;
    for (int i = 0; i < no_nodes; i++) {
        int val;
        cout << "Enter value: ";
        cin >> val;
        ROOT.insert(&ROOT, val);
        ROOT.minimum(&ROOT);
    }
    return 0;
}
