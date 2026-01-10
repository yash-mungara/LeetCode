class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int count=1;
        vector<vector<int>> ans;
        sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y){
            if(x[1]==y[1]) return x[0]>y[0];
            return x[1]<y[1];
        });
        ans.push_back(a[0]);

        for(int i=1;i<a.size();i++){
            int n=ans.size();
            if(ans[n-1][1]>a[i][0]) continue;
            else {
                count++;
                ans.push_back(a[i]);
            }
        }
        return a.size()-count;
    }
};
