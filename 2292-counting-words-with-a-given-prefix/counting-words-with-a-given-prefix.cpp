struct TrieNode{
    TrieNode* children[26] = {nullptr};
    int prefixCount = 0;

    bool containsKey(char c){
        return children[c-'a'] != nullptr;
    }

    void insertKey(char c, TrieNode * node){
        children[c-'a'] = node;
    }
};

class Trie{
private:
    TrieNode * root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insertWord(string word){
        TrieNode * crawler = root;
        for(auto c : word){
            if(!crawler->containsKey(c)){
                crawler->insertKey(c, new TrieNode());
            }
            crawler = crawler -> children[c-'a'];
            crawler->prefixCount++;
        }
    }

    int getCount(string prefix){
        TrieNode * crawler = root;
        for(auto c : prefix){
            if(crawler->containsKey(c)){
                crawler= crawler->children[c-'a'];
            }else{
                return 0;
            }
        }

        return crawler->prefixCount;
    }
};





class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for(auto word : words){
            trie.insertWord(word);
        }

        return trie.getCount(pref);
        
    }
};