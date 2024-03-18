#include <iostream>
#include <string>

using namespace std;

template <typename KeyType, typename ValueType>
struct TreeNode {
    std::pair<KeyType, ValueType> data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::pair<KeyType, ValueType>& data) : data(data), left(nullptr), right(nullptr) {}
};

// Binary tree class
template <typename KeyType, typename ValueType>
class CBinaryTree {
private:
    TreeNode<KeyType, ValueType>* root;

    TreeNode<KeyType, ValueType>* insert(TreeNode<KeyType, ValueType>* node, const std::pair<KeyType, ValueType>& data) {
        if (node == nullptr) {
            return new TreeNode<KeyType, ValueType>(data);
        }

        // Insertion to left node or right 
        if (data.second==0) {
            node->left = insert(node->left, data);
        }
        else if (data.second==1) {
            node->right = insert(node->right, data);
        }

        return node;
    }
public:
    CBinaryTree() : root(nullptr) {}

    // Public function to insert a node
    void insert_new(const std::pair<KeyType, ValueType>& data) {
        root = insert(root, data);
    }

    std::string number;

    // Public function to perform in-order traversal
    void inOrderTraversal(TreeNode<KeyType, ValueType>* node) {
        if (node != nullptr) {
          
            
            if (node->left != nullptr) {
                inOrderTraversal(node->left);
            } 
            
            number.append(std::to_string(node->data.second));


            if (node->right != nullptr) {
                inOrderTraversal(node->right);
            }

            cout << "Node: " << node->data.first << " Code: " << number << endl;
            number = "";
        }
    }

    // Public function to start in-order traversal from the root
    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }
};



