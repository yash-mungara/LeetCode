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
    int diameterOfBinaryTree(TreeNode* root) {
        int x = 0;

        help(root, x);

        return x;
    }

    int help(TreeNode* root, int &x){
        if(!root) return 0;

        int left = help(root->left, x);
        int right = help(root->right, x);

        x = max(x,left+right);

        return max(left, right)+1;
    }
};
