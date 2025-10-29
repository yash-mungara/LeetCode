class Solution {
public:
    long long m = 1e9 + 7;
    long long helper(long long x, long long n, long long base){
        if(n==0) return 1;
        long long  ans = helper(x,n/2,base);
        ans = (ans*ans)%m;
        if(n%2!=0) ans = (ans*base)%m;
        return ans;
    }
    long long myPow(long long x, long long N) {
        if(N<0) {x= 1/x;N=N*-1;}
        long long ans = helper(x,N,x);
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long ans = 0;
        ans = (myPow(4,odd)*myPow(5,even))%m;
        return (int)ans;
    }
};
