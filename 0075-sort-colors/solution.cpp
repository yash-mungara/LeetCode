class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st=0, end=nums.size()-1;
        int i=0, j=end, n=nums.size();
        while(st<n-1 && end>0){
            if(nums[st]==2){
                while(j>0 && j>st && nums[j]==2)j--;
                swap(nums[st],nums[j]);
            }
            if(nums[end]==0){
                while(i<n-1 && i<end && nums[i]==0)i++;
                swap(nums[i],nums[end]);
            }
            st++;end--;
        }
    }
};
