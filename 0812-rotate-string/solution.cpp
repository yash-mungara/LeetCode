class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(n!=goal.size()) return false;
        for(int i=0;i<n;i++){
            if(s==goal) return true;
            else{
                char ch=s[0];
                s.erase(0,1);
                s.push_back(ch);
            }
        }
        return false;
    }
};
