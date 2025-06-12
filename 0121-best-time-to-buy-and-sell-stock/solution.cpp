class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0, bb = prices[0], n = prices.size();
        for(int i=1;i<n;i++){
            if(bb<prices[i]){
                mp = max(mp,prices[i]-bb);
            }
            bb = min(bb,prices[i]);
        }
    return mp;
    }
};
