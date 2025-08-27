class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) return nums[i];
        }
        return nums[0]; 
    }
};
