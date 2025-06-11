class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, num =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(freq==0){
                num = nums[i];
            }
            if(nums[i]==num){
                freq++;
            }else {freq--;}
        }
        return num;
    }
};
