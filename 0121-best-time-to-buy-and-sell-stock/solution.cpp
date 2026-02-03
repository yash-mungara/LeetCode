class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int mini  = a[0], profit = 0;
        for(int i=1;i<n;i++){
            profit = max(a[i]-mini,profit);
            mini = min(mini,a[i]);
        }
        return profit;
    }
};
static int __init = [] {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("user.out", "w", stdout);
    string line;
    while (getline(cin, line))
    {
        int minPrice = INT_MAX, best = 0;
        for (size_t i = 0, n = line.size(); i < n; )
        {
            while (i < n && (line[i] & 15) > 9) ++i;
            if (i >= n) break;
            int price = line[i++] & 15;
            while (i < n && (line[i] & 15) < 10)
                price = price * 10 + (line[i++] & 15);
            if (price < minPrice)
                minPrice = price;
            else
            {
                int profit = price - minPrice;
                if (profit > best) best = profit;
            }
        }
        cout << best << "\n";
    }
    return 0;
}();
