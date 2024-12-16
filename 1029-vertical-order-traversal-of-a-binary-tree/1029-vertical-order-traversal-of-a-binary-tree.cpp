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
        queue<pair<TreeNode*, pair<int, int>>> todo;
        map<int, map<int, multiset<int>>> nodes; 
        todo.push({root, {0,0}});

        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int line = p.second.first;
            int level = p.second.second;

            nodes[line][level].insert(node->val);
            if(node -> left) todo.push({node->left, {line-1, level+1}});
            if(node -> right) todo.push({node->right, {line+1, level+1}});
        }

        vector<vector<int>> ans;
        for(auto it: nodes){
            vector<int> temp;
            for( auto i : it.second){
                temp.insert(temp.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};