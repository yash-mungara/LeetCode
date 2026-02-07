class Solution {
public:
    //int f(int i, int k, vector<int> &arr){
    //    if(i==arr.size()) return 0;
    //    int maxi = INT_MIN, x=-1, cnt=0;
    //    for(int y=i; y < min(i+k,(int)arr.size());y++){
    //        cnt++;
    //        x=max(x,arr[y]);
    //        maxi = max(maxi,x*cnt + f(y+1,k,arr));
    //    }
    //    return maxi;
    //}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxi = INT_MIN, x=-1, cnt=0;
            for(int y=i; y < min(i+k,n);y++){
                cnt++;
                x=max(x,arr[y]);
                maxi = max(maxi,x*cnt + dp[y+1]);
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};
