class Solution {
public:
    // bool dfs(vector<vector<int>>& adj, vector<int> &vis, vector<int> &ans, int i){
    //     vis[i]=1;

    //     for(int neb : adj[i]){
    //         if(vis[neb]==1) return true;    

    //         if(vis[neb]==0) {
    //             if(dfs(adj, vis, ans, neb)) return true;
    //         }
    //     }

    //     vis[i] = 2;
    //     ans.push_back(i);
    //     return false;
    // }
    // vector<int> findOrder(int n, vector<vector<int>>& list) {
    //     vector<vector<int>> adj(n);
    //     vector<int> vis(n,0);
    //     stack<int> st;
    //     vector<int> ans;
    //     for(auto x:list){
    //         adj[x[1]].push_back(x[0]);
    //     }

    //     for(int i=0;i<n;i++){
    //         if(vis[i]==0) {
    //             if(dfs(adj, vis, ans, i)) return {};
    //         }
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }
    vector<int> findOrder(int n, vector<vector<int>>& list) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> ans;
        for(auto x:list){
            adj[x[1]].push_back(x[0]);
            vis[x[0]]++;
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neb: adj[node]){
                vis[neb]--;
                if(vis[neb]==0) q.push(neb);
            }
            ans.push_back(node);
        }
        // reverse(ans.begin(),ans.end());
        if(ans.size()!=n) return {};
        return ans;
    }
};
