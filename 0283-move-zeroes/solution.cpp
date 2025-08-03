class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        while(j<nums.size() && i<nums.size()){
            while(i<nums.size() && nums[i]!=0){i++;}
            while(j<nums.size() && nums[j]==0){j++;}
            if(j<nums.size() && i<nums.size() && i<j){swap(nums[i],nums[j]);i++;}
            j++;
        }
    }
};
