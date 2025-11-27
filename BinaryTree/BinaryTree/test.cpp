#include <iostream>
#include <queue>
#include <functional>
#include "BinarySearchTree.h"

int main() {
	BST<int> bst;
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(7);
	bst.Insert(2);
	bst.Insert(4);
	bst.Insert(6);
	bst.Insert(8);
	bst.InOrderTraversal(); // Expected output: 2 3 4 5 6 7 8
	std::cout << std::endl;
	bst.PreOrderTraversal(); // Expected output: 5 3 2 4 7 6 8
	std::cout << std::endl;
	bst.PostOrderTraversal(); // Expected output: 2 4 3 6 8 7 5
	std::cout << std::endl;
	bst.LevelOrderTraversal(); // Expected output: 5 3 7 2 4 6 8
	std::cout << std::endl;
	std::cout << std::boolalpha << bst.Search(4) << std::endl; // Expected output: true
	std::cout << std::boolalpha << bst.Search(10) << std::endl; // Expected output: false
}