class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), n=triangle[m-1].size();
        vector<int> dp(n);
            dp = triangle[m-1];
        for(int row=m-2;row>=0;row--){
            vector<int> temp(n);
            for(int clm=0;clm<triangle[row].size();clm++){
                temp[clm] = triangle[row][clm];
                temp[clm] += min(dp[clm],dp[clm+1]);
                dp[clm] = temp[clm];
            }

        }
        return dp[0];
    }
};
