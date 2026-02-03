class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        vector<int> x(k+1,0), y(k+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                y[j] = max(-1*a[i] + x[j],y[j]);
                x[j] = max(a[i] + y[j-1],x[j]);
            }
        }
        return y[k];
    }
};
