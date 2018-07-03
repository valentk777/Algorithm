#pragma once
struct Node
{
	Node (int number);
	int value;
	Node* left;
	Node* right;

	void Add (int number);
	bool IsBalanced (int& height);
	void PrintNodes ();
};

class BinarySearchTree
{
public:
	BinarySearchTree ();
	Node* root;

	void Add (int number);
};