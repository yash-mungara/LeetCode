class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for(int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : heights[i]);

            while(!st.empty() && curr < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : (i - st.top() - 1);
                ans = max(ans, h * width);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> helper(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]!='0') helper[j]++;
                else helper[j]=0;
            }
            ans = max(ans,largestRectangleArea(helper));
        }
        return ans;
    }
};
