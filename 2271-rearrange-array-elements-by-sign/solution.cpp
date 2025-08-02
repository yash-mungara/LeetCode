class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), p=0, q=1; 
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[p] = nums[i];
                p+=2;
            } else{
                ans[q] = nums[i];
                q+=2;
            }
        }
        return ans;
    }
};
