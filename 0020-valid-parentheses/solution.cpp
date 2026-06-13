class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char it:s){
            if(it==')' || it=='}' || it==']'){
                if(st.empty()) return false;
                if((it==')' && st.top()!='(') || (it=='}' && st.top()!='{') || (it==']' && st.top()!='[')) return false;
                else st.pop();
            } else{
                st.push(it);
            }
        }
        return st.empty() ? true : false;
    }
};
