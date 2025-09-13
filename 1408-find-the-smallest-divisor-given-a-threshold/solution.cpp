class Solution {
    bool canDivide(int div,int threshold,vector<int>& nums){
        int count=0;
        for(int i=0;i<nums.size();i++){
            int val=(nums[i]+div-1)/div;
            count+=(val);
            if(count>threshold)return false;
        }
        if(count<=threshold)return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans=1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(canDivide(mid,threshold,nums)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};

