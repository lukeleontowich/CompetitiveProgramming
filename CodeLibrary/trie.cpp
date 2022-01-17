#include <iostream>
#include <string>
#include <cassert>

using namespace std;

constexpr int NUM_CHAR_IN_ALPHABET = 26;

class Node {
public:
    Node () {
        for (int i = 0; i < NUM_CHAR_IN_ALPHABET; ++i) {
            children[i] = nullptr;
        }
    }
    ~Node () {}
    char ch;
    Node* children[NUM_CHAR_IN_ALPHABET];
};

class Trie {
public:
    Trie() {
        root = new Node;
    }
    ~Trie() {}

    void insert(const string& s) {
        auto current_node = root;
        for (auto x : s) {
            char xp = tolower(x);
            assert(xp >= 'a' && xp <= 'z');
            if (current_node->children[xp-'a'] == nullptr) {
                current_node->children[xp-'a'] = new Node;
            }
            current_node = current_node->children[xp-'a'];
        }
    }

    bool check(const string& s) {
        auto current_node = root;
        for (auto x : s) {
            char xp = tolower(x);
            assert(xp >= 'a' && xp <= 'z');
            if (current_node->children[xp-'a'] == nullptr) {
                return false;
            }
            current_node = current_node->children[xp-'a'];
        }
        return true;
    }

    void destroy() {
        destroyTree(root);
    }

private:
    Node* root = nullptr;
    void destroyTree(Node* parent) {
        for (int i = 0; i < NUM_CHAR_IN_ALPHABET; ++i) {
            if (parent->children[i] != nullptr) {
                destroyTree(parent->children[i]);
            }
        }
        delete parent;
    }
};


int main () {
    Trie trie;
    trie.insert("Jenna");

    cout << trie.check("Jenna") << "\n";
    cout << trie.check("Luke") << "\n";

    trie.destroy();

    return 0;
}
