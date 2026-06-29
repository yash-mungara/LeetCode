class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});

        // Min-Heap stores: tuple<cost, node, stops_taken>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // Tracks the minimum stops used to reach a node so far
        vector<int> min_stops(n, INT_MAX);

        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            // Rule 1: The Min-Heap guarantees the FIRST time we pull out 'dst', it's the cheapest.
            if (u == dst) return cost;

            // Rule 2: Prune if this state has a higher cost AND takes more/equal stops than a previous run
            if (stops >= min_stops[u]) continue;
            min_stops[u] = stops;

            // Rule 3: Bounded check
            if (stops > k) continue;

            for (auto& [v, wt] : adj[u]) {
                pq.push({cost + wt, v, stops + 1});
            }
        }

        return -1;
    }
};
