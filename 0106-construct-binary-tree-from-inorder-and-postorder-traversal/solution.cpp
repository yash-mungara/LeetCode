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
    map<int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        TreeNode* node = help(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return node;
    }

    TreeNode* help(vector<int> &inorder, int inst, int inend, vector<int> &postorder, int postst, int postend){
        if(postst>postend || inst>inend) return NULL;
        TreeNode*  node = new TreeNode(postorder[postend]);

        int inidx = m[node->val];
        int numsleft = inidx-inst;

        node->right = help(inorder, inidx+1, inend ,postorder, postst+numsleft, postend-1);
        node->left  = help(inorder, inst, inidx-1, postorder, postst, postst+numsleft-1);

        return node;
    }
};
