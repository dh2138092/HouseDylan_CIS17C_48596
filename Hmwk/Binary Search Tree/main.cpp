#include <cstdlib>
#include <iostream>
#include <ctime>

#include "BinarySearchTree.h"

int main(int argc, char* argv[])
{
	BST<int> *tree = new BST<int>();

	srand((unsigned int)time(0));
	int num = 0;
	int const SIZE = 10;

	for (int i = 1; i <= SIZE; i++)
	{
		num = rand() % 15;
		tree->insert(num);
	}

	tree->preorder();
	std::cout << "\n\n";
	tree->postorder();
	std::cout << "\n\n";
	tree->inorder();
	std::cout << "\n\n";

	for (int i = 1; i <= SIZE; i++)
	{
		num = rand() % 15;
		std::cout << "Attempting to remove " << num << " from tree\n";
		tree->findAndDeleteByMerging(num);
		std::cout << '\n';
	}
	
	std::cout << "\n\n";
	tree->preorder();
	std::cout << "\n\n";
	tree->postorder();
	std::cout << "\n\n";
	tree->inorder();
	std::cout << "\n\n";
	
	delete tree;

	return 0;
}
