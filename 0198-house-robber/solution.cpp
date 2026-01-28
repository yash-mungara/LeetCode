class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(), prev=nums[0], prev2=0;

        for(int i=1;i<n;i++){
            int pick = nums[i]+prev2;
            int notpick = prev;

            prev2=prev;
            prev = max(pick,notpick);
        }
        return prev;
    }
};
