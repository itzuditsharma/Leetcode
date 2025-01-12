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
    void Child_parent(TreeNode* root,map<TreeNode*, TreeNode*> &child_parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current -> left ){
                child_parent[current ->left] = current;
                q.push(current -> left);
            }

            if(current -> right){
                child_parent[current -> right] = current;
                q.push(current -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> child_parent;
        Child_parent(root, child_parent);

        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int counter = 0;
        vector<int> ans;

        while(!q.empty()){
            if(counter == k) break;
            counter++;
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left && visited[node -> left] == false){
                    q.push(node -> left); 
                    visited[node -> left] = true;
                }

                if(node -> right && visited[node -> right] == false){
                    q.push(node -> right);
                    visited[node -> right] = true;
                }

                if(child_parent[node] && !visited[child_parent[node]]){
                    q.push(child_parent[node]);
                    visited[child_parent[node]] = true;
                }
            }
        }
        while(!q.empty()){
                ans.push_back(q.front() -> val);
                q.pop();
        }
        return ans;
    }
};