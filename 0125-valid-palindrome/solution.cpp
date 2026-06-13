class Solution {
public:
    bool isalpha(char c){
        return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') ;
    }
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;

        while(i<j){
            while((i<s.size() && j>=0) && !isalpha(s[i])) i++;
            while((i<s.size() && j>=0) && !isalpha(s[j])) j--;
            if(i>=s.size() || j<0) break;
            if(s[i]!=s[j] && tolower(s[i])!=tolower(s[j])) return false;
            i++;j--;
        }
        return true;
    }
};
