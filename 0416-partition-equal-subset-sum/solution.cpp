class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int it:nums) target+=it;
        if(target%2 == 1) return false;
        target = target/2;
        for(int it:nums) if(it>target) return false;

        
        vector<bool> prev(target+1,0), curr(target+1,0);
        prev[0] = 1; prev[nums[0]]=1; curr[0]=1;

        for(int i=1;i<nums.size();i++){
            for(int k=1;k<=target;k++){
                bool nottake = prev[k];
                bool take = false;
                if(k>=nums[i]) take = prev[k-nums[i]];
                curr[k] = take||nottake;
            }
            prev = curr;
        }
        return prev[target];
    }
};
