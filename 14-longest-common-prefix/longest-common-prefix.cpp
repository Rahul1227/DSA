struct TrieNode{
    TrieNode *children[26];
    bool isEnd = false;
    bool containsKey(char c){
        return children[c-'a'] != NULL;
    }

    void insertKey(char c, TrieNode * node){
        children[c-'a'] = node;
    }

    int numberOfChildren(){
        int count =0;
        for(int i =0; i< 26; i++){
            if(children[i] != NULL) count++;

        }
        return count;
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
            crawler = crawler ->children[c-'a'];
        }
        crawler -> isEnd = true;
    }

    TrieNode* getCrawler(){
        return root;
    }
    
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto word : strs){
            trie.insertWord(word);
        }

        string ans ="";
        TrieNode * crawler = trie.getCrawler();
        for(int i =0; i<strs[0].size(); i++){
            if(!crawler -> isEnd && crawler->numberOfChildren()==1){
                ans += strs[0][i];
                crawler = crawler ->children[strs[0][i] - 'a'];
            }else{
                break;
            }

        }

        return ans;
        
    }
};