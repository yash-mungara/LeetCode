class Solution {
public:
    double myPow(double x, int n) {
        double y = 1 , z = x;
        long k = n;
        if(k<0){
            k *= -1;
        while(k>0){
            if(k%2==1){
                y *= z;
            }
            z *= z;
            k /= 2;
        }
        y = 1/y;
        }
        else{
            while(k>0){
            if(k%2==1){
                y *= z;
            }
            z *= z;
            k /= 2;
            }
        }
    return y;
    }
};
