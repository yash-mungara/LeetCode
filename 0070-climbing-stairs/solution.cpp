class Solution {
public:
    int climbStairs(int n) {
        int x=1, y=1;
        for(int i=1;i<n;i++){
            int cnt = x+y;
            x=y;
            y=cnt;
        }
        return y;
    }
};  
