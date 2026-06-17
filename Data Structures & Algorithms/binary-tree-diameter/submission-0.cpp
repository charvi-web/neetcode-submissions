/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int height(TreeNode* root, int &maxD) {
        if (root == nullptr) return 0;
        int lh = height(root->left, maxD);
        int rh = height(root->right, maxD);
        maxD = max(maxD, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        if (root == nullptr) return 0;
        height(root, maxD);
        return maxD;
    }
};
