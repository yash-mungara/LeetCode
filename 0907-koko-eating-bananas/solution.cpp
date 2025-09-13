class Solution {
public:
    int minEatingSpeed(vector<int>& piles, long long h) {
        int n = piles.size();
        int st = 1, end = INT_MIN, mid, ans;
        end = *max_element(piles.begin(), piles.end());    
        
        while(st<=end){
            mid = st+ (end-st)/2;
            long long k=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid==0) k+= (long long)piles[i]/mid;
                else k += (piles[i]/mid)+1;
            }
            if(k<=h) {end = mid-1;ans = mid;}
            else if(k>h) st = mid+1;            
        }
        return ans;
    }
};  
