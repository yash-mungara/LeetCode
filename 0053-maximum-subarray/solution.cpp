class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, n=nums.size(), sum=-10000, ans=sum;
        
        while(i<n){
            if(sum<0 && nums[i]>=sum){sum = nums[i];i++;ans = max(ans,sum);continue;}
            sum+=nums[i];
            i++;
            ans = max(ans,sum);
        }
        return ans;    
    }
};
