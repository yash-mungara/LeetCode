class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int c1 = 0, c2 = 0;
        int v1,v2;
        for(int i=0;i<n;i++){
           if(c1==0 && nums[i]!=v2){
            v1 = nums[i];
            c1++;
           } else if(c2==0 && nums[i]!=v1){
            v2 = nums[i];
            c2++;
           } else if(v1==nums[i]){
            c1++;
           } else if(v2==nums[i]){
            c2++;
           } else {
            c1--;
            c2--;
           }
        }
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i] == v1)c1++;
            else if(nums[i] == v2)c2++;
        }
        if(c1>n/3){
        ans.push_back(v1);
        } 
        if(c2>n/3){
        ans.push_back(v2);
        }
        return ans;
    }
};
