    class Solution {
    public:
        bool ispalin(int i, int j, string& s){
            while(i<j){
                if(s[i]!=s[j]) return false;
                i++;j--;
            }
            return true;
        }
        
        int minCut(string s) {
            int n = s.size();
            vector<int> dp(n+1,0);
            if(ispalin(0,n-1,s)) return 0;

            for(int i=n-1;i>=0;i--){
                    int mini = INT_MAX;
                    for(int k=i;k<n;k++){
                        if(ispalin(i,k,s)) mini = min(1+dp[k+1],mini);
                    }
                    dp[i] = mini;
            }
            return dp[0]-1;
        }
    };
