class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            // 1. If opening bracket, push
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // 2. If closing bracket, stack must not be empty
                if(st.empty()) return false;

                // 3. Check matching pair
                char top = st.top();
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '['))
                {
                    return false;
                }
                
                st.pop();
            }
        }
        
        // 4. Must be empty at end
        return st.empty();
    }
};

