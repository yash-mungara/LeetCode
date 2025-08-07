class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n= arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i][0]<=ans[ans.size()-1][1]){
                if(ans[ans.size()-1][1]<arr[i][1]){
                ans[ans.size()-1][1] = arr[i][1];
                }
            }else {
                ans.push_back({arr[i][0],arr[i][1]});
            }
        }
        return ans;
    }
};
