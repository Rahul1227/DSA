struct TrieNode {
    TrieNode* child[26] = {nullptr};
    bool isValid = false;
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insertWord(string str) {
        TrieNode* crawler = root;
        for (auto c : str) {
            int ind = c - 'a';
            if (crawler->child[ind] == nullptr) {
                crawler->child[ind] = new TrieNode();
            }
            crawler = crawler->child[ind];
            crawler->isValid = true;
        }
        // crawler->isEnd = true;
    
    }

    TrieNode* getRoot(){
        return root;
    }
};

class Solution {
private:
    int solve(int ind, string& target, vector<int>& dp, TrieNode* crawler) {
        int n = target.size();
        if (ind == n) return 0;

        if (dp[ind] != -1) return dp[ind];

        int ans = INT_MAX;
        auto originalCrawler = crawler;
        for(int j = ind; j<target.size(); j++){
            int currInd = target[j] - 'a';
            if(!crawler->child[currInd]) break;
            crawler = crawler->child[currInd];
            if(crawler->isValid){
                int subCall = solve(j+1, target, dp, originalCrawler);
                if(subCall >= INT_MAX) continue;
                ans = min(ans, 1 + subCall);
            }
        }

        

        return dp[ind] = ans;
    }

public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for (auto& w : words) {
            trie.insertWord(w);
        }
        TrieNode* root = trie.getRoot();

        int n = target.size();
        vector<int> dp(n + 1, -1);
        int result = solve(0, target, dp, root);
        return result >= INT_MAX ? -1 : result;
    }
};