class Solution {
public:
    void a(vector<int>& nums,vector<vector<int>>& set,int i,vector<int>& ans){
        if(i==nums.size()){
            set.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        a(nums,set,i+1,ans);

        ans.pop_back();
        a(nums,set,i+1,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> set;
        vector<int> ans;

        a(nums,set,0,ans);
        return set;
    }
};
