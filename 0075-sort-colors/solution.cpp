class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(),a=0,b=0,c=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) a++;
            else if(nums[i]==1) b++;
            else c++;
        }

        int i=0;
        while(a!=0){
            nums[i] = 0;
            a--;i++;
        }
        while(b!=0){
            nums[i] = 1;
            b--;i++;
        }
        while(c!=0){
            nums[i] = 2;
            c--;i++;
        }
    }
};
