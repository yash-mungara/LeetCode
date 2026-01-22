class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> edge(n+1);
        for(auto x:times){
            edge[x[0]].push_back({x[2],x[1]});
        }

        vector<int> time(n+1,1e9);
        set<pair<int,int>> s;

        s.insert({0,k});
        time[k] = 0;

        while(!s.empty()){
            int node=s.begin()->second;
            int tam = s.begin()->first;
            s.erase({tam,node});
            for(auto x:edge[node]){
                int newtime = tam+x.first;
                if(newtime<time[x.second]){
                    if(time[x.second]!=1e9){s.erase({time[x.second],x.second});}
                    time[x.second] = newtime;
                    s.insert({newtime,x.second});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<n+1;i++){
            if(time[i]==1e9) return -1;
            else ans = max(time[i],ans);
        }
        return ans;
    }
};
