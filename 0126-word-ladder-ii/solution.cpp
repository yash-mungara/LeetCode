class Solution {
private:
    string b;
    vector<vector<string>> ans;
    unordered_map<string,int> m;
    void dfs(string word, vector<string> &seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
            for(int i=0;i<word.size();i++){
                char org = word[i];
                int cnt = m[word];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(m.find(word)!=m.end() && m[word]+1==cnt){
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                word[i] = org;
            }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        b=beginWord;
        q.push(beginWord);
        s.erase(beginWord);
        m[beginWord] = 1;

        while(!q.empty()){
            string word = q.front();
            int count = m[word];
            q.pop();
            if(word == endWord) break;
            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(s.find(word)!=s.end()){
                        q.push(word);
                        s.erase(word);
                        m[word] = count+1;
                    }
                }
                word[i] = org;
            }
        }

        if(m.find(endWord)!=m.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
