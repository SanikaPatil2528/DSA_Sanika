class Solution {
private:
    void dfs(string word,vector<string>&curr,vector<vector<string>>&ans,string beginWord,unordered_map<string,int>&mpp){
        if(word==beginWord){
            reverse(curr.begin(),curr.end());
            ans.push_back(curr);
            reverse(curr.begin(),curr.end());
            return ;
        }
        string check=word;
        for(int i=0;i<word.size();i++){
            char orig=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]==mpp[check]-1){
                    curr.push_back(word);
                    dfs(word,curr,ans,beginWord,mpp);
                    curr.pop_back();
                }
            }
            word[i]=orig;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_map<string,int>mpp;
        q.push(beginWord);
        mpp[beginWord]=0;
        int minSteps=0;

        while(!q.empty()){
            string word=q.front();
            q.pop();
            int step=mpp[word];
            if(word==endWord){
                minSteps=step;
                break;
            }
            for(int i=0;i<word.size();i++){
                char orig=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0 && mpp.find(word)==mpp.end()){
                        mpp[word]=step+1;
                        q.push(word);
                    }
                }
                word[i]=orig;
            }
        }

        vector<vector<string>>ans;
        vector<string>curr={endWord};
        dfs(endWord,curr,ans,beginWord,mpp);
        return ans;
    }
};