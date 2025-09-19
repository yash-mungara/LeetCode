class Solution {
public:
    bool solve(vector<int> nums, int k, int mid){
        int y=0, target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
            if(target>mid){
                y++;target = nums[i];
            }
        }y++;
        if(y<=k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size(), mid, ans=0, st=*max_element(nums.begin(),nums.end()), end=0;
        if(k==n) return st;

        for(int i=0;i<n;i++){end+=nums[i];}

        while(st<=end){
            mid=st+(end-st)/2;

            if(solve(nums,k,mid)){
                ans=mid;
                end=mid-1;
            } else st=mid+1;
        }
        return ans;
    }
};
