#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    // Build simple tree:     1
    //                      /   \
    //                     2     3
    //                    / \   /
    //                   4  5  6
    void buildTree() {
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
    }

    // PREORDER: Root-Left-Right
    void preorder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // INORDER: Left-Root-Right  
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    // POSTORDER: Left-Right-Root
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    // Public wrapper methods
    void preorder() { preorder(root); std::cout << std::endl; }
    void inorder() { inorder(root); std::cout << std::endl; }
    void postorder() { postorder(root); std::cout << std::endl; }

    ~BinaryTree() {
        // Simple recursive cleanup
        deleteTree(root);
    }

private:
    void deleteTree(Node* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main()  {
BinaryTree tree;
tree.buildTree();

std::cout << "Preorder:  "; tree.preorder();
std::cout << "Inorder:   "; tree.inorder();
std::cout << "Postorder: "; tree.postorder();

return 0;
}
