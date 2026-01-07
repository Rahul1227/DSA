struct TrieNode {
    TrieNode* children[2];

    bool containsKey(int digit) { return children[digit] != NULL; }

    void insertKey(int digit, TrieNode* node) { children[digit] = node; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insertNum(int num) {
        TrieNode* crawler = root;
        for (int i = 31; i >= 0; i--) {
            int digit =
                (num >> i) & 1; // to get the bit of the num in binary rep
            if (!crawler->containsKey(digit)) {
                crawler->insertKey(digit, new TrieNode());
            }
            crawler = crawler->children[digit];
        }
    }

    int checkAndGet(int num) {
        TrieNode* crawler = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int digit = (num >> i) & 1;
            int toGet = 1 - digit;
            if (crawler->containsKey(toGet)) {
                ans = ans | (1 << i);
                crawler = crawler->children[toGet];

            } else {
                crawler = crawler->children[digit];
            }
        }
        return ans;
    }
};

class Solution {
private:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int len = queries.size();
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }

        sort(queries.begin(), queries.end(), compare);
        sort(nums.begin(), nums.end());
        for (auto query : queries) {
            for (auto i : query) {
                cout << i << " ";
            }
            cout << endl;
        }

        vector<int> result(len, -1);
        int currInd = 0;

        for (auto query : queries) {
            int num = query[0];
            int limit = query[1];
            int ind = query[2];
            while (nums[currInd] <= limit && currInd < nums.size()) {
                trie.insertNum(nums[currInd]);
                currInd++;
            }
            if (currInd == 0)
                continue;

            int ans = trie.checkAndGet(num);

            result[ind] = ans;
        }

        return result;
    }
};