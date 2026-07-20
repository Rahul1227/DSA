class Node {
public:
    Node* lists[26] = {nullptr};
    bool flag = false;
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            int ch = c - 'a';
            if (!node->lists[ch]) {
                node->lists[ch] = new Node();
            }
            node = node->lists[ch];
            node->flag = true;
        }
    }
};

class Solution {
private:
    int solve(int ind, string& target, Node* root, vector<int>& dp) {
        int n = target.size();
        if (ind == n) return 0;

        if (dp[ind] != -1) return dp[ind];

        int ans = INT_MAX;
        Node* node = root;
        for (int j = ind; j < n; j++) {
            int idx = target[j] - 'a';
            if (!node->lists[idx]) break;      // dead end
            node = node->lists[idx];
            if (node->flag) {                   // valid prefix ending here
                int subCall = solve(j + 1, target, root, dp);
                if (subCall < INT_MAX) ans = min(ans, 1 + subCall);
            }
        }

        return dp[ind] = ans;
    }

public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for (auto& w : words) trie.insert(w);

        int n = target.size();
        vector<int> dp(n + 1, -1);
        int result = solve(0, target, trie.root, dp);
        return result >= INT_MAX ? -1 : result;
    }
};