/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root == NULL) return ans;
        int lastval;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node!=NULL){
                lastval = node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }else{
                ans.push_back(lastval);

                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};