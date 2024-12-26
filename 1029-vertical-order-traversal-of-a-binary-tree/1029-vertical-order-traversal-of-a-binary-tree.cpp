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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mapp;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int line = p.second.first;
            int level = p.second.second;

            mapp[line][level].insert(node -> val);
            if(node -> left) q.push({node -> left, {line - 1 , level + 1}});
            if(node -> right) q.push({node -> right, {line + 1 , level + 1}});
        }

        for(auto it : mapp){
            vector<int> col;
            for(auto q : it.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};