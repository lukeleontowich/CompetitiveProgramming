#include <iostream>
#include <cassert>

using namespace std;


template <typename T>
class Node {
public:
    T data;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
};

template<typename T>
class BinaryTree {
public:
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {}
    void insert(const T& element) {
        if (root == nullptr) {
            root = new Node<T>;
            root->data = element;
        } else {
            addNode(root, element);
        }
    }

    void addNode(Node<T>* parent, const T&  element) {
        assert(parent != nullptr);
        if (element <= parent->data) {
            if (parent->left == nullptr)  {
                parent->left = new Node<T>;
                parent->left->data = element;
            } else {
                addNode(parent->left, element);
            }
        } else {
            if (parent->right == nullptr) {
                parent->right = new Node<T>;
                parent->right->data = element;
            } else {
                addNode(parent->right, element);
            }
        }
    }

    Node<T>* newNode(const T& element) {
        Node<T>* temp = new Node<T>;
        temp->data = element;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

    Node<T>* getRoot() {
        return root;
    }

    void destroy() {
        destroyTree(root);
    }

    void destroyTree(Node<T>* parent) {
        if (parent->left != nullptr) {
            destroyTree(parent->left);
        } 
        if (parent->right != nullptr) {
            destroyTree(parent->right);
        }
        delete parent;
    }

private:
    Node<T>* root = nullptr;
};
int main () {
    BinaryTree<int> tree;

    tree.insert(6);
    tree.insert(7);
    tree.insert(5);

    cout << tree.getRoot()->data << "\n";
    if (tree.getRoot()->left != nullptr) {
        cout << "left: " << tree.getRoot()->left->data << "\n";
    }
    if (tree.getRoot()->right != nullptr) {
        cout << "right: " << tree.getRoot()->right->data << "\n";
    }

    tree.destroy();

    return 0;
}
