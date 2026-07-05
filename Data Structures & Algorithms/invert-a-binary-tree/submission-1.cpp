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
TreeNode* invert(TreeNode* n)
{
    if (n==NULL)
    {
        return n;
    }
    invert(n->left);
    invert(n->right);
    swap(n->left,n->right);
    return n;
}
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
