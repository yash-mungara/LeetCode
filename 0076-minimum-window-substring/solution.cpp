class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0, cnt=0, m=s.size(), n=t.size(), len=INT_MAX;
        int arr[256] = {0};
        int st=0;
        for(int i=0;i<n;i++) arr[t[i]-'A']++;

        while(r<m){
            arr[s[r]-'A']--;
            if(arr[s[r]-'A']>=0) cnt++;

            if(cnt==n){
                while(l<m && cnt==n){
                    int temp= r-l+1;
                    if(temp<len){
                        len=temp;
                        st=l;
                    }
                    arr[s[l]-'A']++;
                    if(arr[s[l]-'A']>0) cnt--;
                    l++;
                }
            }
            r++;
        }
        if(len==INT_MAX) return "";
        return s.substr(st,len);    
    }
};
