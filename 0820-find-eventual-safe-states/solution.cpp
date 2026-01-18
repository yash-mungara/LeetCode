class Solution {
private:
    bool dfs(vector<bool> &pathvis, vector<bool> &vis, int i, vector<vector<int>> &graph){
        vis[i] = true; pathvis[i]=true;
        for(int adj:graph[i]){
            if(!vis[adj]){
                if(dfs(pathvis, vis, adj, graph)) return true;
            } else{
                if(pathvis[adj]) return true;
            }
        }
        pathvis[i] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<bool> pathvis(n,false), vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(pathvis, vis, i, graph);
        }
        for(int i=0;i<n;i++){
            if(!pathvis[i]) ans.push_back(i);
        }
        return ans;
    }
};
