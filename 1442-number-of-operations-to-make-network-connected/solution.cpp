class Solution {
public:
    int find(int u, vector<int> &parent){
        if(parent[u]==u) return u;
        else return parent[u] = find(parent[u], parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int V = connections.size();
        if(V<n-1) return -1;

        vector<int> parent(n);
        int extra=0;
        for(int i=0;i<n;i++){ parent[i]=i;}
        for(auto it:connections){
            int u=it[0], v=it[1];
            int prnt_u = find(u,parent);
            int prnt_v = find(v,parent);
            if(prnt_u == prnt_v) extra++;

            else {
                parent[prnt_v] = prnt_u;
            }
        }
        
        return n-1-(V-extra);

    }
};
