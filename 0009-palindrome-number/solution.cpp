class Solution {
public:
    int reverse(int x) {
        int num = 0;

        while(x!=0){
            int dig = x%10;
            if(num > INT_MAX/10 || num < INT_MIN/10){
                return 0;
            }
            num = num*10 +dig;
            x=x/10;
        }
        return num;
    }

    bool isPalindrome(int x) {
        
        if(x<0)return false;
        if(x == reverse(x))return true;
        else return false;
    }
};
