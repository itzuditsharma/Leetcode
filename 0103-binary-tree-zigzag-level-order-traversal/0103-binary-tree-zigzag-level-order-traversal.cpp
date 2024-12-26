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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans; 
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0; //L to R

        while(!q.empty()){
            vector<int> level;
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node -> val);
                if(node -> left) q.push(node ->left);
                if(node -> right) q.push(node ->right);
            }

            if(flag == 0){
                ans.push_back(level);
                flag = 1;
            }else {
                reverse(level.begin(), level.end());
                ans.push_back(level);
                flag = 0;
            }

        }
        return ans;
    }
};