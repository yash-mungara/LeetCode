class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        bool iszero = false, ISzero = false;
        for(int it:nums){
            if(it==0){
                if(iszero) ISzero = true;
                iszero = true;
            } else{
                product *= it;
            }
        }
        vector<int> ans(nums.size(), 0);
        if(ISzero) return ans;
        for(int i=0;i<nums.size();i++){
            if(iszero){
                if(nums[i]!=0) ans[i] = 0;
                else ans[i] = product;
            } else{
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};
