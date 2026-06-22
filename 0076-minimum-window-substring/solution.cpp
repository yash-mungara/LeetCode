class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        int st=-1, l=0, len=INT_MAX, req = t.size(); 
        for(auto it:t){
            m[it]++;
        }

        for(int i=0;i<s.size();i++){
            if(m[s[i]]>0) req--;
            m[s[i]]--;

            while(req==0){
                if(i-l+1<len){
                    len = i-l+1;
                    st = l;
                } 

                m[s[l]]++;
                if(m[s[l]]>0) req++;
                l++;
            }
        }

        return st == -1 ? "" : s.substr(st, len);
    }
};
