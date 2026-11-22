/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void solve(TreeNode* root, string &ans){
        ans += to_string(root->val) + "$";

        // exploring the left substree
        if(root->left){
            solve(root->left, ans);
        }else{
            ans +="#$";
        }

        if(root->right){
            solve(root->right, ans);
        }else{
            ans +="#$";
        }


    }

    TreeNode* buildTree(queue<string> &q){
        string currVal = q.front();
        q.pop();
        if(currVal == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(currVal));
        root->left = buildTree(q);
        root->right = buildTree(q);

        return root;


    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;

        solve(root, ans);
        return ans;

        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        queue<string> q;
        stringstream ss(data);
        string word;
        while(getline(ss, word, '$')){
            q.push(word);
        }

        return buildTree(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));