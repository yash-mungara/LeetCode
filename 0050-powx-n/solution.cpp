class Solution {
public:
    double helper(double x, long long n, double base){
        if(n==0) return 1;
        double ans = helper(x,n/2,base);
        ans = ans*ans;
        if(n%2!=0) ans = ans*base;
        return ans;
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N<0) {x= 1/x;N=N*-1;}
        double ans = helper(x,N,x);
        return ans;
    }
};
