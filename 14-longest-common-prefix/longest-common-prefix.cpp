struct TrieNode{
    TrieNode * child[26] = {nullptr};
    int count =0;

};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode;
    }

    void insertWord(string word){
        TrieNode * craw = root;

        for(auto c : word){
            int ind = c-'a';
            if(craw->child[ind] == nullptr){
                craw->child[ind] = new TrieNode;
            }
            craw = craw->child[ind];
            craw->count++;
        }
    }

    TrieNode* getRoot(){
        return root;
    }

};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto word: strs){
            trie.insertWord(word);
        }
        TrieNode* root = trie.getRoot();
        int n = strs.size();

        string ans = "";
        for(int i=0; i<strs[0].size(); i++){
            int ind = strs[0][i] -'a';
            if(root->child[ind] == nullptr){
                return ans;
            }
            root = root->child[ind];
            if(root->count == n){
                ans.push_back(strs[0][i]);
            }else{
                return ans;
            }
        }

        return ans;
    }
};