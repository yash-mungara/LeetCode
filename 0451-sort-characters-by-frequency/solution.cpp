class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i:s){
            m[i]++;
        }  
        vector<pair<char,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),[](auto &a, auto &b){
            return a.second>b.second;
        });
        string ans;
        int i=0, j=0;
        while(i<s.size()){
            while(v[j].second>0){
                ans.push_back(v[j].first);
                v[j].second--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
