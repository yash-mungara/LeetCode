class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        
        vector<vector<int>> ans;
        if(a.size()==0) {
            ans.push_back(b);
            return ans;
        }
        int j=0;
            for(int i=0;i<a.size();i++){
                if(b[0]>a[i][1]){
                    ans.push_back(a[i]);
                } else{
                    if(b[1]<a[i][1] && b[0]<a[i][0]){
                        ans.push_back({b[0],b[1]});
                        break;
                    } else{
                    ans.push_back({min(a[i][0],b[0]),max(a[i][1],b[1])});
                    j=i+1;
                    break;
                    }
                }
            }

            for(j;j<a.size();j++){
                int n=ans.size();
                if(ans[n-1][1]>=a[j][0]) ans[n-1][1] = max(ans[n-1][1],a[j][1]);
                else ans.push_back(a[j]);
            }
            if(b[0]>ans[ans.size()-1][1]){
                ans.push_back({b[0],b[1]});
            }
            return ans;
    }
};
