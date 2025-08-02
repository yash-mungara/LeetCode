class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = nums.size()-1, high = nums.size() - 1;

        while(mid >= low){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid]);
            }
            else if(nums[mid] == 1){
                mid--;
            }
            else{ // nums[mid] == 2
                swap(nums[mid--], nums[high--]);
            }
        }
    }
};
