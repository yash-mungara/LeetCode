class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans,y;
        int n= s.length(), count=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            else count--;
            y.push_back(s[i]);

            if(count==0){
                y.pop_back();
                y.erase(0,1);
                ans = ans+y;
                y.clear();
            }
        }
        return ans;
    }
};
