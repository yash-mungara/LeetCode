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
    int helpl(TreeNode* node){
        int height = 0;
        while(node!=NULL){
            height++;
            node = node->left;
        }
        return height;
    }
    int helpr(TreeNode* node){
        int height = 0;
        while(node!=NULL){
            height++;
            node = node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int l = helpl(root);
        int r = helpr(root);

        if(l==r) return (1<<l) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
