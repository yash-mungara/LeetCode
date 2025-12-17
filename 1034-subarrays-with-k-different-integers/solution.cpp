class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k==0) return 0;
        unordered_map<int,int> m;   
        int i=0, j=0, ans=0, freq=0;
        while(j<nums.size()){
            m[nums[j]]++;
            if(m[nums[j]]==1) freq++;
            while(freq>k){
                m[nums[i]]--;
                if(m[nums[i]]==0) {
                    freq--;
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return helper(nums,k)-helper(nums,k-1);
    }
};
