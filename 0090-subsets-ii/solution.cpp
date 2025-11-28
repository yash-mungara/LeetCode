class Solution {
public:
    void helper(vector<int>& nums, int i,vector<int>& giver, set<vector<int>>& ans){
        if(i>=nums.size()){
            vector<int> temp=giver;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        giver.push_back(nums[i]);
        helper(nums,i+1,giver,ans);
        giver.pop_back();
        helper(nums,i+1,giver,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> giver;

        helper(nums, 0, giver, ans);
        vector<vector<int>> answer(ans.begin(),ans.end());
        return answer;
    }
};
