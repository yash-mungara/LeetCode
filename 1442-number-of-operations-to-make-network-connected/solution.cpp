class Solution {
public:
    vector<int> parent, size;

    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findpar(parent[node]);
    }
    void ubysize(int node1, int node2){
        int p1 = findpar(node1), p2 = findpar(node2);
        if(p1==p2) return;

        if(size[p1]<size[p2]){
            parent[p1] = p2;
            size[p2] += size[p1];
        } else{
            parent[p2] = p1;
            size[p1] += size[p2];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parent.resize(n); size.resize(n,1);
        unordered_set<int> s;
        for(int i=0;i<n;i++) parent[i] = i;

        for(auto it:connections){
            ubysize(it[0], it[1]);
        }

        for(int i=0;i<n;i++){
            int x = findpar(i);
            s.insert(x);
        }
        return s.size()-1;
    }
};
