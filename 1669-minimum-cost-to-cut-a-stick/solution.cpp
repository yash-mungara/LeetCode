class Solution {
public:
    int f(int i, int j, vector<int>& cuts){
        if(i>j) return 0;
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1] + f(i,k-1,cuts) + f(k+1,j,cuts);
            mini = min(cost,mini);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(),0);cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2, vector<int> (c+2,0));

        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
                int mini = INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][k-1]  + dp[k+1][j];
                    mini = min(cost,mini);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};
