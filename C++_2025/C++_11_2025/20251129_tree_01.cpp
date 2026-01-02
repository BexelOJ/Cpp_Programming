#include <iostream>
#include <memory>

struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    void insert(int v) {
        insertImpl(root, v);
    }

    void inorder() const {
        inorderImpl(root.get());
        std::cout << "\n";
    }
private:
    std::unique_ptr<Node> root;

    void insertImpl(std::unique_ptr<Node> &node, int v) {
        if (!node) {
            node = std::make_unique<Node>(v);
            return;
        }

        if (v < node->value) {
            insertImpl(node->left, v);
        }
        else
            insertImpl(node->right, v);
    }
    
    void inorderImpl(const Node* node) const {
        if (!node) return;
        inorderImpl(node->left.get());
        std::cout << node->value << ' ';
        inorderImpl(node->right.get());
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);

    std::cout << "Inorder Traversal: ";
    bst.inorder();
}