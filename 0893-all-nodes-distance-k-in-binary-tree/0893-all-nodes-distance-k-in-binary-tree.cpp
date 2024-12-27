/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &child_parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current -> left){
                child_parent[current->left] = current; 
                q.push(current -> left);
            }
            if(current -> right){
                child_parent[current -> right] = current;
                q.push(current -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Marking Parents 
        unordered_map<TreeNode*, TreeNode*> child_parent;
        mark_parents(root, child_parent);

        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int cur_increment = 0;

        while(!q.empty()){
            int size = q.size();
            if(cur_increment == k) break;
            cur_increment++;

            for(int i = 0;i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                // Left Child 
                if(node -> left && visited[node-> left] == false){
                    visited[node -> left] = true;
                    q.push(node -> left);
                }
                // Right Child 
                if(node -> right && visited[node-> right] == false){
                    visited[node -> right] = true;
                    q.push(node -> right);
                }
                // Parent 
                if(child_parent[node] && !visited[child_parent[node]]){
                    visited[child_parent[node]] = true;
                    q.push(child_parent[node]);
                }

            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};