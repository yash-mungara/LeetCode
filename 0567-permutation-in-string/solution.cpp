class Solution {
public:
    bool ismatch(int a[],int b[]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
       int freq[26] = {0};

       for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
       } 


       for(int i=0;i<s2.length();i++){
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};   
        while(windIdx < s1.length() && idx<s2.length()){
            windFreq[s2[idx]-'a']++;
            idx++;windIdx++;
        }
        if(ismatch(freq, windFreq)) return true;
       }
       return false;
    }
};
