class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool iszero = false;
        int i=nums.size()-2;
        int step=0;

        while(i>=0){
            if(nums[i]==0){iszero = true;} 
            if(iszero){
                if(nums[i]>step){
                    iszero=false;
                    step=0;
                } else{
                    step++;
                }
            }
            i--;
        }
        return !iszero;
    }
};
