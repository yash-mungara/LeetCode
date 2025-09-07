class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int st = 0, end = nums.size()-1;
        int mid;
        while(st<=end){
            mid = st + (end-st)/2;
            if(nums[mid]==target) break;
            else if(nums[mid]>target){
                end = mid-1;
            } else{
                st = mid+1;
            }
        }
        int a = mid;
        if(nums.size()==0 || nums[mid]!=target) return ans;
        while(mid>=0 && nums[mid]==target) mid--;
        if(nums[++mid]==target) ans[0] = mid;
        while(a<nums.size() && nums[a]==target) a++;
        if(nums[--a]==target) ans[1] = a;
        return ans;
    }
};
