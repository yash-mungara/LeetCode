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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<tuple<int,int,int>> list;
        queue<pair<int, TreeNode*>> q;
        q.push({0,root});
        int timer=0;
        int minclm = 0, maxclm =0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().second;
                int clm = q.front().first;
                q.pop();
                if(node->left!=NULL) {q.push({clm-1,node->left}); minclm = min(minclm,clm-1);}
                if(node->right!=NULL) {q.push({clm+1,node->right}); maxclm = max(maxclm, clm+1);}
                list.emplace_back(node->val, timer, clm);
            }
            timer++;
        }
        sort(list.begin(), list.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
            if(get<2>(a) != get<2>(b)) {
                return get<2>(a) < get<2>(b);
            }
            if(get<1>(a) != get<1>(b)) {
                return get<1>(a) < get<1>(b);
            }
            return get<0>(a) < get<0>(b);
        });
        ans.resize(maxclm-minclm+1);
        for(auto it:list){
            int clm = get<2>(it), value = get<0>(it);
            ans[clm-minclm].push_back(value);
        }
        return ans;
    }
};
