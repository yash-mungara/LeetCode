class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
            sort(a.begin(),a.end(),[](const vector<int> &b, const vector<int> &c){
                return b[0]<c[0];
            });
            ans.push_back(a[0]);
            for(int i=1;i<a.size();i++){
                if(a[i][0]>ans[ans.size()-1][1]) ans.push_back(a[i]);
                else{
                    int n=ans.size();
                    ans[n-1][1] = max(ans[n-1][1],a[i][1]);
                }
            }
            return ans;
    }
};
