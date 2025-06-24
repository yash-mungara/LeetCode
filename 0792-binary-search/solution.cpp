class Solution {
public:
    int bin(vector<int>& nums, int target,int st,int end){
        if(st<=end){
        int mid = st + (end-st)/2;
        
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target) return bin(nums, target, st, mid-1);
        else return bin(nums, target, mid+1, end);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return bin(nums,target,0,nums.size()-1);
    }
};
