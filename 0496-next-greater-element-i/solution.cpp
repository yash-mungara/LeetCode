class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> st;

        for(int i = nums2.size() - 1; i >= 0; i--) {
            // Remove all smaller or equal elements
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack empty → no greater element
            if(st.empty()) m[nums2[i]] = -1;
            else m[nums2[i]] = st.top();

            // Push current element
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int x : nums1) {
            ans.push_back(m[x]);
        }

        return ans;
    }
};

