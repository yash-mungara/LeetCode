class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int n = a.size();
        int x=0, y=0;
        for(int i=n-1;i>=0;i--){
            y = max(-1*a[i] + x,y);
            x = max(a[i]+y-fee,x);
        }
        return y;
    }
};
