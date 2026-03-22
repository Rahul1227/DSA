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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string tree  = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(!node){
                tree += "#,";
                continue;
            }
            int val = node->val;
            tree += to_string(val) + ',';
            if(node->left){
                q.push(node->left);
            }else{
                q.push(NULL);
            }

            if(node->right){
                q.push(node->right);
            }else{
                q.push(NULL);
            }
        }
        // for(auto c : tree){
        //     cout<<c<<" ";
        // }
        return tree;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n == 0) return NULL;
        queue<TreeNode*> q;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(ss, str, ',');
            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(ss, str, ',');
            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        


        


        return root;

        

      
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));