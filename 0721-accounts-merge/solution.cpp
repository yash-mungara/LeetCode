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

    void unionbysize(int u, int v){
        int ult_u = findparent(u);
        int ult_v = findparent(v);
        if(ult_v == ult_u) return;
        if(size[ult_u]<size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
        } else{
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& account) {
        int n=account.size();
        Disjoint ds(n);
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<account[i].size();j++){
                string mail = account[i][j];
                if(m.find(mail)==m.end()){
                    m[mail] = i;
                } else{
                    ds.unionbysize(m[mail],i);
                }
            }
        }
        vector<vector<string>> helper(n);

        for(auto it:m){
            string mail = it.first;
            int node = ds.findparent(it.second);
            helper[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(helper[i].size()==0) continue;
            int node = ds.findparent(m[helper[i][0]]);
            sort(helper[i].begin(),helper[i].end());
            vector<string> temp;
            temp.push_back(account[node][0]);
            for(auto it:helper[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
