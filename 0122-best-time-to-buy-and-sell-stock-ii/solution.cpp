class Solution {
public:
    int f(int i, int perm, vector<int> &a){
        if(i>=a.size()) return 0;
        if(perm){
            int take = -1*a[i] + f(i+1,0,a);
            int nottake = f(i+1,1,a);
            return max(take,nottake);
        }
            int take1 = a[i]+f(i+1,1,a);
            int nottake1 = f(i+1,0,a);
            return max(take1,nottake1);
    }
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int x=0, y=0;
        for(int i=n-1;i>=0;i--){
            y = max(-1*a[i] + x,y);
            x = max(a[i]+y,x);
        }
        return y;
    }
};
