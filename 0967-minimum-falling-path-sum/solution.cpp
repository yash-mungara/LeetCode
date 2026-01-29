class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n+2,INT_MAX);
        for(int i=0;i<n;i++){ dp[i+1] = matrix[n-1][i];}

        for(int row=n-2;row>=0;row--){
            vector<int> temp(n);
            for(int clm=0;clm<n;clm++){
                temp[clm] = matrix[row][clm];
                temp[clm] += min(dp[clm],min(dp[clm+1],dp[clm+2]));
            }
            for(int i=0;i<n;i++){dp[i+1] = temp[i];}
        }

        int ans=INT_MAX;
        for(int it:dp){ans = min(ans,it);}
        return ans;
    }
};
