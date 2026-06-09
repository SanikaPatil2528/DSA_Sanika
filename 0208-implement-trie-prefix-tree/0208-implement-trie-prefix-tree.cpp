struct Node{
    Node* links[26];
    bool flag=false;
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            if(!(curr->links[word[i]-'a'])){
                curr->links[word[i]-'a']=new Node();
            }
            curr=curr->links[word[i]-'a'];
        }
        curr->flag=true;
    }
    
    bool search(string word) {
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            if(!(curr->links[word[i]-'a'])) return false;
            curr=curr->links[word[i]-'a'];
        }
        if(curr->flag==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *curr=root;
        for(int i=0;i<prefix.size();i++){
            if(!(curr->links[prefix[i]-'a'])) return false;
            curr=curr->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */