class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1,true);
        int count = 0;

        for(int i=2;i<n;i++){
            if(isprime[i]){
                count++;
            
            for(int j=2*i;j<n;j+=i){
                isprime[j]=false;
            }
            }
        } 
        return count;
    }
};
