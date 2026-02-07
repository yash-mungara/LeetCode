class Solution {
public:
    int f(int i, int j, vector<int>& nums){
        if(i>j) return 0;
        int maxi = INT_MIN;
        for(int k=i;k<=j;k++){
            int coins = nums[k]*nums[i-1]*nums[j+1] + f(i,k-1,nums) + f(k+1,j,nums);
            maxi = max(maxi,coins);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2,0));
        nums.insert(nums.begin(),1); nums.push_back(1);

        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxi = INT_MIN;
                for(int k=i;k<=j;k++){
                    int coins = nums[k]*nums[i-1]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};
