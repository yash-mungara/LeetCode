class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int v){
        vis[v] = 1;

        for(int u:adj[v]){
            if(!vis[u]){dfs(adj,vis,u);}
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        int ans = 0;
        //creating adjlist 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

    /*    for(int i=0;i<n;i++){
            if(vis[i]) continue;            DFS
            ans++;
            dfs(adj,vis,i);
        }
    */

        

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            queue<int> q;
            vis[i] = 1;
            q.push(i);
            ans++;
            while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int u:adj[node]){
                if(!vis[u]) {
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
        }
        return ans;
    }
};
