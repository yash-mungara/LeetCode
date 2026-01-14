class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            int step = q.front().second;
            string word = q.front().first;
            q.pop();
            if(word==endWord) return step;

            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(s.find(word)!=s.end()){
                        q.push({word,step+1});
                        s.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};
