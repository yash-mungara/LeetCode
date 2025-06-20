class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0; int n = chars.size();
        for(int i=0;i<n;i++){
            int count = 0; char ch = chars[i];
            while(i<n && chars[i]==ch){
                count++;i++;
            }
            i--;
            chars[idx] = ch;
            idx++;
            if(count>1){
                std::string s = std::to_string(count);     
                for(int j=0;j<s.size();j++){
                    chars[idx] = s[j];idx++;
                }
                
            }
        }
        return idx;
    }
};
