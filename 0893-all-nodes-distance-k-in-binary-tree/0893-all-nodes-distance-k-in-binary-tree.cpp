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
    void assignParent(TreeNode* root, map<TreeNode*, TreeNode*> &child_parent){
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
        map<TreeNode*, TreeNode*> childParent;
        assignParent(root, childParent);

        queue<TreeNode*> q;
        q.push(target);
        int iterations = 0;
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        while(!q.empty()){
            int size = q.size();
            if(iterations == k) break;
            iterations++;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                // Left child 
                if(node -> left && visited[node->left] == false){
                    visited[node->left] = true;
                    q.push(node -> left);
                }
                // Right child 
                if(node -> right && visited[node -> right] == false){
                    visited[node -> right] = true;
                    q.push(node -> right);
                }
                // Up 
                if(childParent[node] && visited[childParent[node]] == false){
                    visited[childParent[node]] = true;
                    q.push(childParent[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};