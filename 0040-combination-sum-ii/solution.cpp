class Solution {
public:
    void helper(vector<int>& candidates, int target, int i, vector<int>& giver, set<vector<int>>& ans){
        if(target==0){
            vector<int> temp = giver;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        if(i>=candidates.size() || target<0){
            return;
        }

        giver.push_back(candidates[i]);
        helper(candidates, target-candidates[i], i+1, giver, ans);
        giver.pop_back();
        
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]){i++;}
        helper(candidates, target, i+1, giver, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> giver;
        sort(candidates.begin(),candidates.end());
        helper(candidates, target, 0, giver, ans);
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};
