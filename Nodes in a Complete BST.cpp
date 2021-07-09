#include <math.h>

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
    int countNodes(TreeNode* root) 
    {
        if (!root) { return 0; }
        int height = getHeight(root);
        if (height == 0) { return 1; }
        int count = pow(2, height) - 1;
        int left = 0, right = count;
        while (left < right)
        {
            int idxToFind = ceil((left + right) / 2);
            if (nodeExists(idxToFind, height, root))
            {
                left = idxToFind;
            }
            else
            {
                right = idxToFind - 1;
            }
        }
        return count + left + 1;
    }
    int getHeight(TreeNode* root)
    {
        int height = 0;
        while (root->left != nullptr)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    bool nodeExists(int nodeIdx, int height, TreeNode* node)
    {
        int left = 0, right = pow(2, height) - 1, count = 0;
        while (count < height)
        {
            int mid = ceil((left + right) / 2);
            if (nodeIdx >= mid)
            {
                node = node->right;
                left = mid;
            }
            else
            {
                node = node->left;
                right = mid - 1;
            }
            count++;
        }
        return node != nullptr;
    }
};