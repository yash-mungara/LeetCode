class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, curr=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(ans<0) ans = 0;
                curr=1;
                continue;
            }
            curr*=nums[i];
            ans = max(curr,ans);
        }
        curr = 1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                curr=1;
                continue;
            }
            curr*=nums[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};
