#include <math.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        traverse(root, 0);
    }
    int traverse(TreeNode* node, int count)
    {
        if (!node)
        {
            return count;
        }
        count++;
        return fmax(traverse(node->left, count), traverse(node->right, count));
    }
};