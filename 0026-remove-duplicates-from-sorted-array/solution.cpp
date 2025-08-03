class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, k=0, x=0;
        while(i<nums.size()){
            while(i<nums.size() && nums[i]==nums[x]){i++;}
            if(i>=nums.size()) break;
            nums[++x] = nums[i];
        }
        return x+1;
    }
};
