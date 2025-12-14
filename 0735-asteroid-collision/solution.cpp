class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> ans;
        int i=0;
        while(i<n){
            while(i<n && !st.empty() && st.top()>0 && arr[i]<0){
                if(arr[i]*-1 > st.top()) st.pop();
                else if(arr[i]*-1 < st.top()){
                    i++;
                } else{
                    st.pop();i++;
                }
            }


            if(i<n) st.push(arr[i]);
            i++;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
