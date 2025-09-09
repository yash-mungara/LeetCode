class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size()-1;
        int Min = INT_MAX;
        while(st<=end){
            int mid = st + (end-st)/2;

            if(nums[mid]>=nums[st]){
                Min = min(nums[st],Min);
                st = mid+1;
            }
            else{
                Min = min(nums[mid],Min);
                end = mid-1;
            }
        }
        return Min;
    }
};
