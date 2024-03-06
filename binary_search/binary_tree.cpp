#include <iostream>
using namespace std;

struct Node {
    string key;
    string value;
    Node *left, *right;
};

Node* insert(Node* root, string key, string value) {
    if (root == NULL) {
        root = new Node;
        root->key = key;
        root->value = value;
        root->left = root->right = NULL;
    } else if (root->key < key) {
        root->right = insert(root->right, key, value);
    } else {
        root->left = insert(root->left, key, value);
    }
    return root;
}



string find_min(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->key;
}

Node* delete_node(Node* root, string key) {
    if (root == NULL) {
        return root;
    }
    
    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } else {
        //Если у текущего узла нет левого потомка, то текущий узел заменяется правым потомком.
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        //Если у текущего узла нет правого потомка, то текущий узел заменяется левым потомком.
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        string min_key = find_min(root->right);
        root->key = min_key;
        root->right = delete_node(root->right, min_key);
    }
    
    return root;
}

void reverse_inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    reverse_inorder(root->right);
    
    cout << root->key << " ";
    
    reverse_inorder(root->left);
}

int main() {
    Node* root = NULL;
    root = insert(root, "7", "1");
    root = insert(root, "3", "2");
    root = insert(root, "5", "3");
    root = insert(root, "1", "4");
    root = insert(root, "9", "5");
    root = insert(root, "4", "6");
    root = insert(root, "8", "7");
    root = insert(root, "6", "8");
    root = insert(root, "2", "9");

    root = delete_node(root, "5");
    
    reverse_inorder(root);

    return 0;
}
