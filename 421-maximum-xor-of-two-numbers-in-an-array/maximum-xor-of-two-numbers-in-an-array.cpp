struct TrieNode{
    TrieNode* child[2] ={nullptr};
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insertNum(int n){
            TrieNode* crawler = root;
            for(int i=31; i>=0; i--){
                int val = (n>>i) & 1;
                if(!crawler->child[val]){
                    crawler->child[val] = new TrieNode();
                }
                crawler = crawler->child[val];
            }
        }

        int getXOR(int num){
            TrieNode* crawler = root;
            int ans = 0;

            for(int i=31; i>=0; i--){
                int val = (num >> i) & 1;
                int target = 1 - val;
                if(crawler->child[target]){
                    ans = ans | (1 << i);
                    crawler = crawler->child[target];
                }else{
                    crawler = crawler->child[val];
                }
            }

            return ans;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;
        for(auto num: nums){
            trie.insertNum(num);
        }

        int maxAns = 0;
        for(auto num: nums){
            int currVal = trie.getXOR(num);
            maxAns = max(maxAns, currVal);
        }

        return maxAns;
        
    }
};