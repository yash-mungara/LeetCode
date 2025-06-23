class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        vector<int> vec;
        for(int i=0;i<n;i++){
            int fst = nums[i];
            int sec = target - fst;
            if(map.find(sec)!=map.end()){
                vec.push_back(i);vec.push_back(map[sec]);
                return vec;}
            map[fst] = i;
        }
        return vec;
    }

};
    
