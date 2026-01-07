struct TrieNode {
    bool isEnd = false;
    string word = "";
    TrieNode* children[26];

    bool containsKey(char c) { return children[c - 'a'] != nullptr; }

    void insertKey(char c, TrieNode* node) { children[c - 'a'] = node; }

    TrieNode* getChild(char c) { return children[c - 'a']; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insertWord(string s) {
        TrieNode* crawler = root;
        for (char c : s) {
            if (!crawler->containsKey(c)) {
                crawler->insertKey(c, new TrieNode());
            }
            crawler = crawler->getChild(c);
        }
        crawler->isEnd = true;
        crawler->word = s;
    }

    TrieNode* getRoot() { return root; }
};

class Solution {
private:
    void dfs(int row, int col, TrieNode* node, vector<vector<char>>& board,
             vector<string>& ans) {

        char currentChar = board[row][col];

        // Check if current character exists in trie
        if (!node->containsKey(currentChar)) {
            return;
        }

        // Move to the next trie node
        node = node->getChild(currentChar);

        // If we found a word, add it to result
        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false; // Avoid duplicate entries
        }

        // Mark current cell as visited by temporarily changing it
        board[row][col] = '#';

        int m = board.size();
        int n = board[0].size();
        int dirX[] = {-1, 1, 0, 0};
        int dirY[] = {0, 0, 1, -1};

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirX[i];
            int newCol = col + dirY[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                board[newRow][newCol] != '#') {
                dfs(newRow, newCol, node, board, ans);
            }
        }

        // Backtrack: restore the cell
        board[row][col] = currentChar;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie trie;

        // Build trie with all words
        for (const string& word : words) {
            trie.insertWord(word);
        }

        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        TrieNode* root = trie.getRoot();

        // Try starting DFS from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, root, board, ans);
            }
        }

        return ans;
    }
};