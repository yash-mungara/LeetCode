class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0,s,path,ans);
        return ans;
    }
    void func(int idx, string s, vector<string>& path,vector<vector<string>>& ans){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispalin(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                func(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    bool ispalin(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};
