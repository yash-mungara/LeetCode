class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int freq=0, n=nums.size(), ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) freq++;
            else{
                ans = max(ans,freq);
                freq=0;
            }
        }
        ans = max(ans,freq);
        return ans;
    }
};
