class Solution {
public:
    int f(int i, int cmp, vector<int> &nums, vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i][cmp]!=-1) return dp[i][cmp];
        int nottake = f(i+1,cmp,nums,dp);
        int take = 0;
        if(cmp==0 || nums[i]>nums[cmp-1]){
            take = 1+ f(i+1,i+1,nums,dp);
        }
        return dp[i][cmp] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        ans.push_back(nums[0]);

        for(int i =1; i<nums.size(); i++){

            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{

                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i]; 

            }

        }


        return ans.size();
    }
};
