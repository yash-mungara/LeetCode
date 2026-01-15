class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, int i,int cnt){
        vis[i] = cnt;
        for(int x:graph[i]){
            if(vis[x]==-1){
                if(dfs(graph,vis,x,!cnt)==false) return false;
            } else if(vis[x]==vis[i]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);

        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if(dfs(graph,vis,i,0)==false) return false;
            }
        }
        return true;
    }
};
