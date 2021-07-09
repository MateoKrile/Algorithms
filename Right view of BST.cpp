#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
		if (!root) { return {}; }
		vector<int> result;
		TreeNode* currentNode;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int levelCount = q.size();
			int count = 0;
			while (levelCount > count)
			{
				currentNode = q.front();
				q.pop();
				if (currentNode->left)
				{
					q.push(currentNode->left);
				}
				if (currentNode->right)
				{
					q.push(currentNode->right);
				}
				count++;
			}
			result.push_back(currentNode->val);
		}
		return result;
    }
};