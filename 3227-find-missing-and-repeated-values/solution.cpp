class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> set;
        int n = grid.size(),a,sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                if(set.find(grid[i][j])!=set.end()){
                    ans.push_back(grid[i][j]);
                    a=grid[i][j];
                }
                set.insert(grid[i][j]);
            }
        }
        int b=n*n;
        b=(b*(b+1))/2;
        b = b + a -sum;
        ans.push_back(b);
        return ans;
    }
};
