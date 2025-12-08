class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long help=0;
        int k=0,y=0;
        vector<int> ans;

        for(auto x:nums){
            help = help^x;
        }

        help = (help&(help-1))^help;

        for(auto x:nums){
            if((x&help) == help) k = k^x;
            else y=y^x;
        }
    
        ans.push_back(k);
        ans.push_back(y);
        return ans;    
    }
};
