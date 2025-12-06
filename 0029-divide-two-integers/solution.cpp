class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign = true;

        if((dividend >= 0 && divisor<0) || (dividend<0 && divisor>=0)) sign = false; //negative

        long n = abs((long)dividend); long d = abs((long)divisor);
        long ans = 0;

        while(n>=d){
            int cut = 0;
            
            while(n>=(d<<(cut+1))) cut++;

            ans+= (1L<<cut);
            n -=  d*(1L<<cut);
        }
        
        if(ans > INT_MAX) return sign ? INT_MAX : INT_MIN;

        return sign ? ans : -1*ans;
    }
};
