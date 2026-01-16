class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& crs) {
        vector<vector<int>> adj(V);
        stack<int> st;
        vector<int> indg(V,0);
        vector<int> ans;

        for(int i=0;i<crs.size();i++){
            adj[crs[i][1]].push_back(crs[i][0]);
        }

        for(auto x:adj){for(auto y:x){indg[y]++;}}

        for(int i=0;i<indg.size();i++){
            if(indg[i]==0) st.push(i);
        }

        while(!st.empty()){
            int node = st.top();
            ans.push_back(node);
            st.pop();
            for(int i=0;i<adj[node].size();i++){
                indg[adj[node][i]]--;
                if(indg[adj[node][i]]==0){
                    st.push(adj[node][i]);
                }
            }
        }
        return ans.size()==V;
    }
};
