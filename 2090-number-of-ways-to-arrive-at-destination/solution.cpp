class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<long long,int>>> adj(n);
        for(auto x: roads){
            adj[x[0]].push_back({x[2], x[1]});
            adj[x[1]].push_back({x[2], x[0]});
        }

        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>>pq;   // 🔧 long long
        vector<long long> dis(n, 1e18); // 🔧 long long
        vector<long long> ways(n, 0);

        ways[0] = 1;
        dis[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto node = pq.top().second;
            auto dist = pq.top().first;
            pq.pop();

            for(auto x:adj[node]){
                auto ndis = dist + x.first;

                if(ndis<dis[x.second]){
                    ways[x.second] = ways[node];
                    dis[x.second] = dist+x.first;
                    pq.push({dis[x.second],x.second});
                } else if(ndis==dis[x.second]){
                    ways[x.second] = (ways[x.second]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};

