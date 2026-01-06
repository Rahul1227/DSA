struct TrieNode{
    bool isEnd = false;
    TrieNode * children[26];

    bool containsKey(char c){
        return children[c-'a'] != NULL;
    }

    void insertKey(char c, TrieNode * node){
        children[c-'a'] = node;
    }
};

class Trie {
private:
    TrieNode * root;
public:
    Trie() {
        root = new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode * crawler = root;
        for(auto c : word){
            if(!crawler->containsKey(c)){
                crawler->insertKey(c, new TrieNode());
            }
            crawler = crawler->children[c-'a'];
        }
        crawler->isEnd = true;
        
    }
    
    bool search(string word) {
        TrieNode * crawler = root;
        for(auto c : word){
            if(!crawler->containsKey(c)) return false;
            crawler = crawler->children[c-'a'];
        }

        return crawler->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode * crawler = root;
        for(auto c: prefix){
            if(!crawler->containsKey(c)) return false;
            crawler = crawler->children[c-'a'];
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