struct TrieNode{
    TrieNode* child[2] = {nullptr};
  
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode;
    }

    void insertNum(int num){
        TrieNode* crawler = root;

        for(int i = 31; i>=0; i--){
            int digit =(num  >> i) & 1;

            if(crawler->child[digit] == nullptr){
                crawler->child[digit] = new TrieNode;
            }
            crawler = crawler->child[digit];
        }
    }

    int getResult(int num){
        int ans = 0;
        TrieNode* craw = root;
        for(int i=31; i>=0; i--){
            int digit = (num >> i) & 1;
            int toGet = 1 - digit;
            if(craw->child[toGet]){
                ans = ans | (1 << i);
                craw = craw->child[toGet];
            }else{
                craw = craw ->child[digit];
            }
        }

        return ans;
    }



};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto num : nums){
            trie.insertNum(num);
        }

        int maxResult = 0;
        for(auto num : nums){
            int currResult = trie.getResult(num);
            maxResult = max(maxResult, currResult);
        }

        return maxResult;
        
    }
};