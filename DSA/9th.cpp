#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct avl_node {
    string keyword;
    string meaning;
    struct avl_node *left;
    struct avl_node *right;
} *root;

class avl_tree {
public:
    int height(avl_node *);
    int difference(avl_node *);
    avl_node *rr(avl_node *);
    avl_node *ll(avl_node *);
    avl_node *lr(avl_node *);
    avl_node *rl(avl_node *);
    avl_node *balance(avl_node *);
    avl_node *insert(avl_node *, string, string);
    void display(avl_node *, int);
    avl_tree() {
        root = NULL;
    }
};

int avl_tree::height(avl_node *temp) {
    int h = 0;
    if (temp != NULL) {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int avl_tree::difference(avl_node *temp) {
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int balance_factor = l_height - r_height;
    return balance_factor;
}

avl_node *avl_tree::rr(avl_node *parent) {
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avl_tree::ll(avl_node *parent) {
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avl_tree::lr(avl_node *parent) {
    avl_node *temp;
    temp = parent->left;
    parent->left = rr(temp);
    return ll(parent);
}

avl_node *avl_tree::rl(avl_node *parent) {
    avl_node *temp;
    temp = parent->right;
    parent->right = ll(temp);
    return rr(parent);
}

avl_node *avl_tree::balance(avl_node *temp) {
    int balance_factor = difference(temp);
    if (balance_factor > 1) {
        if (difference(temp->left) > 0)
            temp = ll(temp);
        else
            temp = lr(temp);
    } else if (balance_factor < -1) {
        if (difference(temp->right) > 0)
            temp = rl(temp);
        else
            temp = rr(temp);
    }
    return temp;
}

avl_node *avl_tree::insert(avl_node *root, string key, string meaning) {
    if (root == NULL) {
        root = new avl_node;
        root->keyword = key;
        root->meaning = meaning;
        root->left = NULL;
        root->right = NULL;
        return root;
    } else if (key < root->keyword) {
        root->left = insert(root->left, key, meaning);
        root = balance(root);
    } else if (key >= root->keyword) {
        root->right = insert(root->right, key, meaning);
        root = balance(root);
    }
    return root;
}

void avl_tree::display(avl_node *ptr, int level) {
    int i;
    if (ptr != NULL) {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr != root) {
            for (i = 0; i < level; i++)
                cout << " ";
        } else {
            cout << "Root -> ";
        }
        cout << ptr->keyword << "(" << ptr->meaning << ")";
        display(ptr->left, level + 1);
    }
}

int main() {
    int choice;
    string key, meaning;
    avl_tree avl;
    while (1) {
        cout << "\n\tAVL Tree Operations\n";
        cout << "1. Insert Keyword and Meaning" << endl;
        cout << "2. Display Balanced AVL Tree" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> key;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                root = avl.insert(root, key, meaning);
                break;
            case 2:
                if (root == NULL) {
                    cout << "Tree is Empty" << endl;
                } else {
                    cout << "Balanced AVL Tree:" << endl;
                    avl.display(root, 1);
                }
                break;
            case 3:
                exit(1);
                return 0;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}