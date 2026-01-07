struct TrieNode{
    TrieNode * children[2];

    bool containsKey(int digit){
        return children[digit] != NULL;
    }

    void insertKey(int digit, TrieNode * node){
        children[digit] = node;
    }

};

class Trie{
private:
    TrieNode * root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insertNum(int num){
        TrieNode * crawler = root;
        for(int i = 31; i>=0; i--){
            int digit = (num>>i) & 1; // to get the bit of the num in binary rep
            if(!crawler->containsKey(digit)){
                crawler->insertKey(digit, new TrieNode());
            }
            crawler = crawler ->children[digit];
        }
    }


    int checkAndGet(int num){
        TrieNode * crawler = root;
        int ans = 0;
        for(int i = 31; i>=0; i--){
            int digit = (num >> i) & 1;
            int toGet = 1 - digit;
            if(crawler->containsKey(toGet)){
                ans = ans | ( 1 << i);
                crawler = crawler -> children[toGet];

            }else{
                crawler = crawler->children[digit];
            }
        }
        return ans;
    }




};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // inserting into the trie
        Trie trie;
        for(auto num : nums){
            trie.insertNum(num);
        }
        int maxResult = INT_MIN;

        for(auto num : nums){
            int currResult = trie.checkAndGet(num);
            maxResult = max(maxResult, currResult);
        }

        return maxResult;
        
    }
};