#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree
{
private:
    void _insert(Node<T>*& node, T data)
    {
        if (node == nullptr)
        {
            node = new Node<T>(data);
        }
        else if (node->data > data )
        {
            this->_insert(node->left, data);
        }
        else
        {
            this->_insert(node->right, data);
        }
    }

    bool _search(Node<T> *node, T data) const
    {
        if (node->data == data)
        {
            return true;
        }
        else if (node->data < data)
        {
            this->_search(node->right, data);
        }
        else
        {
            this->_search(node->left, data);
        }
        return false;
    }

    void _inorderTraversal(Node<T> *node) const
    {
        if (node != nullptr)
        {
            this->_inorderTraversal(node->left);
            std::cout<<node->data << " ";
            this->_inorderTraversal(node->right);
        }
    }
    void _preorderTraversal(Node<T> *node) const
    {
        if (node != nullptr)
        {
            std::cout<<node->data << " ";
            this->_preorderTraversal(node->left);
            this->_preorderTraversal(node->right);
        }
    }
    void _postorderTraversal(Node<T> *node) const
    {
        if (node != nullptr)
        {
            this->_postorderTraversal(node->left);
            this->_postorderTraversal(node->right);
            std::cout<<node->data << " ";
        }
    }

public:
    Node<T> *root = nullptr;

    void insert(T data)
    {
        this->_insert(this->root, data);
    }

    bool search(T data) const
    {
        return this->_search(this->root, data);
    }

    void inorderTraversal() const
    {
        this->_inorderTraversal(this->root);
    }

    void preorderTraversal() const
    {
        this->_preorderTraversal(this->root);
    }

    void postorderTraversal() const
    {
        this->_postorderTraversal(this->root);
    }
};

int main()
{
     // Create a binary tree for integers
    BinaryTree<int> intTree;
    intTree.insert(5);
    intTree.insert(3);
    intTree.insert(8);
    intTree.insert(1);
    intTree.insert(4);

    std::cout << "In-order traversal of integer binary tree:" << std::endl;
    intTree.inorderTraversal();

    // Create a binary tree for strings
    BinaryTree<std::string> stringTree;
    stringTree.insert("banana");
    stringTree.insert("apple");
    stringTree.insert("cherry");
    stringTree.insert("date");

    std::cout << "\nIn-order traversal of string binary tree:" << std::endl;
    stringTree.inorderTraversal();
    return 0;
}