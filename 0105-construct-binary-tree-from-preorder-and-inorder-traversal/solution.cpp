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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }

        TreeNode* node = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size());

        return node;
    }
    TreeNode* helper(vector<int> & preorder, int prest, int preend, vector<int>& inorder, int inst, int inend){
        if(prest>preend || inst>inend) return NULL;
        TreeNode* node = new TreeNode(preorder[prest]);

        int data = m[node->val];
        int numsleft = data-inst;

        node->left = helper(preorder, prest+1, prest+numsleft, inorder, inst, data-1);
        node->right = helper(preorder, prest+numsleft+1, preend, inorder, data+1, inend);

        return node;
    }
};
