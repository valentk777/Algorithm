#include "stdafx.h"
#include "Searchs.h"

Node::Node (int number)
	: value (number), left (nullptr), right (nullptr)
{}

void Node::Add (int number)
{
	if (number <= value)
	{
		if (left == nullptr)
			left = new Node (number);
		else
			left->Add (number);
	}
	else
	{
		if (right == nullptr)
			right = new Node (number);
		else
			right->Add (number);
	}
}

bool Node::IsBalanced (int& height)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if (left != nullptr && !left->IsBalanced (leftHeight))
	{
		return false;
	}

	if (right != nullptr && !right->IsBalanced (rightHeight))
	{
		return false;
	}

	if (leftHeight > rightHeight) {
		if (leftHeight - rightHeight > 1)
		{
			return false;
		}
		height = leftHeight + 1;
	}
	else
	{
		if (rightHeight - leftHeight > 1)
		{
			return false;
		}
		height = rightHeight + 1;
	}
	return true;
}

void Node::PrintNodes ()
{
	if (left != nullptr)
	{
		left->PrintNodes ();
	}
	printf ("%d ", value);
	if (right != nullptr)
		right->PrintNodes ();
}

BinarySearchTree::BinarySearchTree () {}

void BinarySearchTree::Add (int number)
{
	if (root == nullptr)
	{
		root = new Node (number);
	}
	else
	{
		root->Add (number);
	}
}