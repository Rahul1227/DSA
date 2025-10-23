class Trie {
public:
    Trie * children[26];
    bool isLeaf;
    Trie() {
        isLeaf = false;
        for(int i =0;  i<26; i++){
            children[i] = nullptr;
        }
        
    }
    
    void insert(string word) {
        Trie* curr = this;

        for(auto c : word){
            if(curr->children[c -'a'] == nullptr){
                Trie* newNode = new Trie();
                curr->children[c-'a'] = newNode;

            }
            curr = curr->children[c-'a'];
        }
        curr->isLeaf = true;
        
    }
    
    bool search(string word) {
        Trie* curr = this;

        for(auto c: word){
            if(curr->children[c-'a'] == nullptr) return false;
            curr = curr->children[c-'a'];
        }
        return curr->isLeaf;
        
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(auto c : prefix){
            if(curr->children[c-'a'] == nullptr) return false;
            curr = curr->children[c-'a'];
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