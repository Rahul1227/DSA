// using piii = pair<int,pair<int,int>>;

struct TrieNode{
    TrieNode* child[2] = {nullptr};
};

class Trie{
private:
    TrieNode * root;
public:
    Trie(){
        root = new TrieNode;
    }

    void insertNum(int num){
        TrieNode* craw = root;
        
        for(int i =31; i>=0; i--){
            int digit = (num >> i) & 1;
            if(craw->child[digit] ==  nullptr){
                craw->child[digit] = new TrieNode;
            }
            craw = craw->child[digit];
        }
    }

    int getResult (int num){
        int ans =0;
        TrieNode* craw = root;

        for(int i=31; i>=0; i--){
            int digit = (num >> i) & 1;
            int toGet = 1 - digit;
            if(craw->child[toGet]  != nullptr){
                ans = ans | (1 << i);
                craw = craw->child[toGet];
            }else{
                craw = craw->child[digit];
            }
        }

        return ans;
    }



};


class Solution {
public:
    static bool compare(vector<int> &a, vector<int> b){
        return a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i =0; i<queries.size(); i++){
            queries[i].push_back(i);
        }

        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), compare);
        int queryLen = queries.size();
        vector<int> ans(queryLen);

        int inserted = 0;
        Trie trie;
        int n = nums.size();
        for(auto query : queries){
            int givenNum = query[0];
            int limit = query[1];

            while(inserted < n && nums[inserted] <= limit){
                trie.insertNum(nums[inserted]);
                inserted++;
            }
            int result = -1;
            if(inserted> 0){
                result = trie.getResult(givenNum);
            }
            int ind = query[2];
            ans[ind] = result;
        }

        return ans;
        
    }
};