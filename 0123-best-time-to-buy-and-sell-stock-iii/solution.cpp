class Solution {
public:
    int f(int i, int perm, int lim,vector<int> &a){
        if(lim==0) return 0;
        if(i>=a.size()) return 0;

        if(perm){
            return max(-1*a[i] + f(i+1,0,lim,a),f(i+1,1,lim,a));
        }
        return max(a[i] + f(i+1,1,lim-1,a),f(i+1,0,lim,a));
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<int> x(3,0), y(3,0);
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=2;j++){
                y[j] = max(-1*a[i] + x[j],y[j]);
                x[j] = max(a[i] + y[j-1],x[j]);
            }
        }
        return y[2];
    }
};
