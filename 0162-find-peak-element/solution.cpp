class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n-1, mid;
            
            if(n==1 || nums[0] > nums[1]) return 0;
            if(nums[n-1]>nums[n-2]) return n-1;
            
        while(st<=end){
            mid = st + (end-st)/2;

            if(mid==0) st = mid+1;
            else if(mid==n-1) end = mid-1;
            
            if(mid>0 && mid<n-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;

            else if(mid>0 && mid<n-1 && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]) st = mid+1;

            else if(mid>0 && mid<n-1 && nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]) end = mid-1;

            else st = mid+1;
        }

        return 0;
    }
};
