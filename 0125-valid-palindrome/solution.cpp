class Solution {
public:
    bool isalpha(char a){
        if((a>='0'&&a<='9') || (a>='a'&& a<='z') || (a>='A' && a<='Z')) return true;
        else return false;
    }
    bool isPalindrome(string s) {
        int st = 0, end = s.size()-1;
        while(st<end){
            if(!isalpha(s[st])){st++;continue;}
            if(!isalpha(s[end])){end--;continue;}
            if(tolower(s[st])!=tolower(s[end])){return false;}
            st++;end--;
        }
        return true;
    }
};
