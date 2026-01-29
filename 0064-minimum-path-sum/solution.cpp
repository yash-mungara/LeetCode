class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> dp(n+1,INT_MAX);
        dp[n-1] = 0;
        for(int row=m-1;row>=0;row--){
            vector<long long> temp(n+1,INT_MAX);
            for(int clm=n-1;clm>=0;clm--){
                temp[clm] = grid[row][clm];
                temp[clm] = min(temp[clm+1]+temp[clm],temp[clm]+dp[clm]);
            }
            dp = temp;
        }
        return (int)dp[0];
    }
};
