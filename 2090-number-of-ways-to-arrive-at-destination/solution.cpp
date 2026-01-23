class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x: roads){
            adj[x[0]].push_back({x[2], x[1]});
            adj[x[1]].push_back({x[2], x[0]});
        }

        set<pair<long long,int>> s;   // 🔧 long long
        vector<long long> dis(n, 1e18); // 🔧 long long
        vector<int> ways(n, 0);

        int m = 1e9 + 7;

        s.insert({0, 0});
        dis[0] = 0;
        ways[0] = 1;

        while(!s.empty()){
            auto [dist, node] = *s.begin();
            s.erase(s.begin());

            if(dist > dis[node]) continue;  // 🔧 safety check

            for(auto x : adj[node]){
                long long nd = dist + x.first;

                if(dis[x.second] > nd){
                    if(dis[x.second] != 1e18)
                        s.erase({dis[x.second], x.second});

                    dis[x.second] = nd;
                    ways[x.second] = ways[node];
                    s.insert({nd, x.second});
                }
                else if(dis[x.second] == nd){
                    ways[x.second] = (ways[x.second] + ways[node]) % m;
                }
            }
        }
        return ways[n-1];
    }
};

