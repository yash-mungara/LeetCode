class Solution {
public:
    bool checkValidString(string s) {
        int min=0, max=0;
        for(char x:s){
            if(x=='(') {
                min++;
                max++;
            } else if(x==')'){
                min--;
                max--;
            } else{
                min--;
                max++;
            }

            if(max<0) return false;
            if(min<0) min=0;
        }
        return min==0;
    }
};
