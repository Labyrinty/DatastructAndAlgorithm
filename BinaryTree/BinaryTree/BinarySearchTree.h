#ifndef BinarySearchTree_H
#define BinarySearchyTree_H

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(const T& value = T(), BinaryTreeNode* leftval = nullptr, BinaryTreeNode* rightval = nullptr) : data(value), left(leftval), right(rightval) {}
};

template <typename T>
class BinarySearchTree {
private:
	BinaryTreeNode<T>* root;
public:
	BinarySearchTree() : root(nullptr) {}
	~BinarySearchTree() { Clear(); }

	void Insert(BinaryTreeNode<T>** root, const T& value);
	T& Search(const T& value);
	const T& Search(const T& value) const;
	void InOrderTraversal(BinaryTreeNode<T>* node, void (*visit)(T&));
	void Clear();
};

#endif