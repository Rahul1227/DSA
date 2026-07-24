struct TrieNode {
    TrieNode* child[26] = {nullptr};
    // bool isEnd = false;
    int ind = -1;

     ~TrieNode(){
        for(int i=0; i<26; i++){
            delete child[i];
        }
     }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode; 
    }

    ~Trie(){
        delete root;
    }


    void insertWord(int idx, vector<string>& wordsContainer) {
        string word = wordsContainer[idx];
        reverse(word.begin(), word.end());
        TrieNode* craw = root;

        for (auto c : word) {
            int ind = c - 'a';
            if (!craw->child[ind]) {
                craw->child[ind] = new TrieNode;
            }
            craw = craw->child[ind];
            if (craw->ind == -1) {
                craw->ind = idx;
            } else {
                if(word.size() < wordsContainer[craw->ind].size()){
                    craw->ind = idx;
                }else if(word.size() == wordsContainer[craw->ind].size()){
                    craw->ind = min(craw->ind, idx);
                }
            }
        }
    }

    int getAns(string word) {
        reverse(word.begin(), word.end());
        TrieNode* craw = root;
        if (!craw->child[word[0] - 'a'])
            return -1;
        for (auto c : word) {
            int ind = c - 'a';
            if (craw->child[ind]){
                craw = craw->child[ind];
            }else{
                return craw->ind;
            }
        }

        return craw->ind;
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int defaultInd = 0;
        int maxSize = INT_MAX;
        Trie trie;
        for(int i =0; i< wordsContainer.size(); i++){
            
            string word = wordsContainer[i];
            trie.insertWord(i, wordsContainer);
            int currLen = word.size();
            if(currLen < maxSize){
                maxSize = currLen;
                defaultInd = i;
            }

        }

        vector<int> ans;
        for(auto word: wordsQuery){
            int result = trie.getAns(word);
            if(result == -1){
                ans.push_back(defaultInd);
            }else{
                ans.push_back(result);
            }
        }

        return ans;
    }
};