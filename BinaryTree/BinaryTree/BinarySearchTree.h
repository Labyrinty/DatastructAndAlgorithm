#ifndef BINARY_SEARCH_TREE_H  
#define BINARY_SEARCH_TREE_H

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(const T& value = T(), BinaryTreeNode* leftval = nullptr, BinaryTreeNode* rightval = nullptr)
        : data(value), left(leftval), right(rightval) {
    }
};

template <typename T>
class BST {
public:
    BinaryTreeNode<T>* root;
    BST() : root(nullptr) {}
    ~BST() { Clear(); }

    void Insert(const T& value);
    bool Search(const T& value);
    const bool Search(const T& value) const;
    void LevelOrderTraversal();
    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();
    void Clear();
};

template <typename T>
void BST<T>::Insert(const T& value) {
    std::function<BinaryTreeNode<T>* (BinaryTreeNode<T>*, const T&)> insert = [&](BinaryTreeNode<T>* node, const T& val) -> BinaryTreeNode<T>*{
        if (node == nullptr) {
            return new BinaryTreeNode<T>(val);
        }
        if (val <= node->data) {
            node->left = insert(node->left, val);
        }
        else {
            node->right = insert(node->right, val);
        }
        return node;
        };
    root = insert(root, value);  // 添加了 root = 
}

template <typename T>
bool BST<T>::Search(const T& value) {
    BinaryTreeNode<T>* current = root;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        else if (value <= current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

template <typename T>
const bool BST<T>::Search(const T& value) const {
    const BinaryTreeNode<T>* current = root;  // 改为 const 指针
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        else if (value <= current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

template <typename T>
void BST<T>::LevelOrderTraversal() {
    if (root == nullptr) return;
    std::queue<BinaryTreeNode<T>*> q;  // 改为存储指针
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<T>* current = q.front();
        q.pop();
        std::cout << current->data << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

template <typename T>
void BST<T>::InOrderTraversal() {
    std::function<void(BinaryTreeNode<T>*)> inOrder = [&](BinaryTreeNode<T>* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
        };
    inOrder(root);
}

template <typename T>
void BST<T>::PreOrderTraversal() {
    std::function<void(BinaryTreeNode<T>*)> preOrder = [&](BinaryTreeNode<T>* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
        };
    preOrder(root);
}

template <typename T>
void BST<T>::PostOrderTraversal() {
    std::function<void(BinaryTreeNode<T>*)> postOrder = [&](BinaryTreeNode<T>* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
        };
    postOrder(root);
}

template <typename T>
void BST<T>::Clear() {
    std::function<void(BinaryTreeNode<T>*)> clear = [&](BinaryTreeNode<T>* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
        };
    clear(root);
    root = nullptr;
}

#endif