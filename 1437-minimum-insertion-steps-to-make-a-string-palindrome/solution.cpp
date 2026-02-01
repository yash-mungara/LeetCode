class Solution {
public:
    int f(int i, int j, string &s, string &s1, vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i+j+1<=s.size()) return 0;
        if(s[i]==s1[j]) return dp[i][j] = f(i-1,j-1,s,s1,dp);
        else{
            return dp[i][j] = min(1+f(i-1,j,s,s1,dp),1+f(i,j-1,s,s1,dp));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        if(n==1) return 0;
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<int> curr(n,0), prev(n,0);
        for(int i=0;i<n;i++){
            if(s[0]==s[i]) prev[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+j+1<=s.size()) continue;
                if(s[i]==s1[j]) curr[j] = prev[j-1];
                else curr[j] = min(1+prev[j],1+curr[j-1]);
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
