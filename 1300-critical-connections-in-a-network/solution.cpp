class Solution {
private: 
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int> &vis, vector<int> &low, 
    vector<int> &tin, vector<vector<int>> &ans, vector<vector<int>> &adj){
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;

        for(auto it:adj[node]){
            if(it == parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,low,tin,ans,adj);
                low[node] = min(low[node],low[it]);
                    if(tin[node]<low[it]){
                        ans.push_back({node,it});
                    }
                
            } else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), ans;
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0), tin(n), low(n);
        dfs(0,-1,vis,low,tin,ans,adj);
        return ans;
    }
};
