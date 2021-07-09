#include <limits>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
	bool isValidBST(TreeNode* root)
	{
		if (!root) { return true; }
		return DFS(root, LONG_MIN, LONG_MAX);
	}
	bool DFS(TreeNode* node, long min, long max)
	{
		if (node->val > max || node->val < min) { return false; }
		if (node->left)
		{
			if (!DFS(node->left, min, node->val)) { return false; }
		}
		if (node->right)
		{
			if (!DFS(node->right, node->val, max)) { return false; }
		}
		return true;
	}
};