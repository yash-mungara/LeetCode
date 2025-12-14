class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    const int mod = 1e9+7;
    int n = arr.size();
    vector<int> ple(n), nle(n);
    stack<int> st;

    // PLE → strictly greater
    for (int i=0; i<n; i++) {
        while (!st.empty() && arr[i]<arr[st.top()]) st.pop();
        ple[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // NLE → greater or equal
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && arr[i]<=arr[st.top()]) st.pop();
        nle[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long ans = 0;
    for (int i=0; i<n; i++) {
        long long left = i - ple[i];
        long long right = nle[i] - i;
        ans = (ans + (arr[i] * left % mod * right % mod) % mod) % mod;
    }

    return (int)ans;
}
};
