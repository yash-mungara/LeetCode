class Solution {
public:
    void helper(vector<int>& candidates, int target, int i, vector<vector<int>>& ans,vector<int>& giver){
        if(target==0) {
            ans.push_back(giver);
            return;
        }
        if(i>=candidates.size() || target<0){
            return;
        }
        giver.push_back(candidates[i]);   
        helper(candidates, target - candidates[i], i, ans, giver);
        giver.pop_back();
        
        helper(candidates, target, i+1, ans, giver);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> giver;
        helper(candidates, target, 0, ans, giver);
        return ans;
    }
};
