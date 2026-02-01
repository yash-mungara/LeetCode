class Solution {
public:
    int f(int i1,int i2,string s, string t, vector<vector<int>> &dp){
        if(i2<0) return 1;
        if(i1<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(s[i1]==t[i2]) return dp[i1][i2] = f(i1-1,i2-1,s,t,dp)+f(i1-1,i2,s,t,dp);
        return dp[i1][i2] = f(i1-1,i2,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n1=s.size(), n2=t.size();
        vector<double> prev(n2+1,0), curr(n2+1,0);
        prev[0] = 1;
        for(int i1=1;i1<=n1;i1++){
            curr[0] = 1;
            for(int i2=1;i2<=n2;i2++){
                if(s[i1-1]==t[i2-1]) curr[i2] = prev[i2-1]+prev[i2];
                else curr[i2] = prev[i2];
            }
            prev = curr;
        }
        return (int)prev[n2];
    }
};
