#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node(int val)
	{
		value = val;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree
{
public:
	Node* root;
	BinarySearchTree()
	{
		root = nullptr;
	}
	void Insert(int value)
	{
		Node* newNode = new Node(value);
		if (!root)
		{
			root = newNode;
		}
		else
		{
			auto currentNode = root;
			while (true)
			{
				if (currentNode->value > value)
				{
					if (!currentNode->left)
					{
						currentNode->left = newNode;
						return;
					}
				}
				else
				{
					if (!currentNode->right)
					{
						currentNode->right = newNode;
						return;
					}
				}
				currentNode = currentNode->right;
			}
		}
	}
};

void BFS(Node* root)
{
	Node* currentNode;
	queue<Node*> q;
	q.push(root);
	vector<int> tree;
	while (!q.empty())
	{
		currentNode = q.front();
		q.pop();
		tree.push_back(currentNode->value);
		if (currentNode->left)
		{
			q.push(currentNode->left);
		}
		if (currentNode->right)
		{
			q.push(currentNode->right);
		}
	}
	for (int i : tree)
	{
		cout << tree[i] << " ";
	}
	cout << endl;
}

void DFS(Node* root)
{
	if (!root)
	{
		return;
	}
	DFS(root->left);
	DFS(root->right);
}