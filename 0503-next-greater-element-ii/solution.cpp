class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),INT_MIN);
        int i=nums.size()-1;

        while(i>=0){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }

            if(!st.empty()) ans[i] = st.top();
            st.push(nums[i]);
            i--;
        }       
        i=nums.size()-1;
        while(i>=0){
            if(ans[i]==INT_MIN){
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                if(!st.empty()) ans[i]=st.top();
                else ans[i]=-1;
            }
            i--;
        }
        return ans; 
    }
};
