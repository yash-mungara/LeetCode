class Solution {
public:
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        
        if(amount==0) return 1;
        if(i==0){
            if(amount%coins[i]==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take = 0;
        if(amount>=coins[i]) take = f(i,amount-coins[i],coins,dp);
        int nottake = f(i-1,amount,coins,dp);
        return dp[i][amount] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<long long> prev(amount+1,0);
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i] = 1;
        }

        for(int idx=1;idx<n;idx++){
            vector<long long> curr(amount+1,0);
            for(int k=0;k<=amount;k++){
                int take = 0;
                if(k>=coins[idx]) take = curr[k-coins[idx]];
                int nottake = prev[k];
                curr[k] = (long long)take+nottake;
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};
