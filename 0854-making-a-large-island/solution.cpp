class Disjoint {
    vector<int> size,rank,parent;
public: 
    Disjoint(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findparent(int node){
        if(parent[node]==node) return node;
        else return parent[node] = findparent(parent[node]);
    }

    int count(int node){
        int x = findparent(node);
        return size[x];
    }

    void unionbyrank(int u, int v){
        int ult_u = findparent(u);
        int ult_v = findparent(v);
        if(ult_v == ult_u) return;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u] = ult_v;
        } else if(rank[ult_u]>rank[ult_v]){
            parent[ult_v] = ult_u;
        } else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }

    void unionbysize(int u, int v, int &ans){
        int ult_u = findparent(u);
        int ult_v = findparent(v);
        if(ult_v == ult_u) return;
        if(size[ult_u]<size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
            ans = max(ans,size[ult_v]);
        } else{
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
            ans = max(ans,size[ult_u]);
        }
    }
};

class Solution {
    vector<int> dr = {0,-1,0,1};
    vector<int> dc = {-1,0,1,0};
    int ans=1;
private: 
    bool isvalid(int r, int c, int n){
        return r<n && c<n && c>=0 && r>=0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int node = i*n + j;
                    for(int k=0;k<2;k++){
                        int adjr = i+dr[k], adjc = j+dc[k];
                        if(isvalid(adjr, adjc, n) && grid[adjr][adjc]){
                            int adjnode = adjr*n + adjc;
                            ds.unionbysize(node, adjnode, ans);
                        }
                    }
                }
            }
        }
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) continue;
                
                int node = i*n+j;
                for(int k=0;k<4;k++){
                    int adjr = i+dr[k], adjc = j+dc[k];
                    if(isvalid(adjr,adjc,n) && grid[adjr][adjc]){
                        int adjnode = adjr*n+adjc;
                        s.insert(ds.findparent(adjnode));
                    }
                }
                    int cnt=1;

                for(auto x:s){
                    cnt+= ds.count(x);
                }
                s.clear();
                    ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
