class Solution {
public:
    set<vector<int>> s;
    void help(vector<int>& arr, int target,int idx,vector<int> &comb,vector<vector<int>>& ans){
        if(idx == arr.size() || target<0){
            return ;
        }

        if(target == 0){
            if(s.find(comb) == s.end()){
            ans.push_back({comb});
            s.insert(comb);
            }
            return;
        }
        comb.push_back(arr[idx]);
        help(arr,target-arr[idx],idx+1,comb,ans);
        help(arr,target-arr[idx],idx,comb,ans);
        comb.pop_back();
        help(arr,target,idx+1 ,comb,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        help(arr,target,0,comb,ans);
        return ans;
    }
};
