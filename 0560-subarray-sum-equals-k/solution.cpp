class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(),count =0;
        vector<int> ps(n,0);
        ps[0] = arr[0];
        for(int i=1;i<n;i++){
            ps[i] = ps[i-1] + arr[i];
        }

        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(ps[i]==k)    count++;

            int val = ps[i] - k;
            if(m.find(val)!=m.end()){
                count += m[val];
            }

            if(m.find(ps[i])==m.end()){
                m[ps[i]] = 0;
            }
            m[ps[i]]++;
        }
        return count;
    }
};
