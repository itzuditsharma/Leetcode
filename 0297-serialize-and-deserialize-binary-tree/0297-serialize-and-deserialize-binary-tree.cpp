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
        string s = "";
        if(root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){
                s.append("#,");
            }else{
                s.append(to_string(node -> val) + ",");
            }
            if(node != NULL){
                q.push(node-> left);
                q.push(node -> right);
            }
        }   
        return s;     
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        string s;
        stringstream ss(data);
        getline(ss, s, ',');
        TreeNode* root = new TreeNode(stoi(s));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(ss, s, ',');
            if(s == "#"){
                node -> left = NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(s));
                node -> left = leftNode;
                q.push(leftNode);
            }

            getline(ss, s, ',');
            if(s == "#"){
                node -> right = NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(s));
                node -> right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));