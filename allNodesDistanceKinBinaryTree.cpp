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
    
    void makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        makeParent(root,parent);
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> flag;
        q.push(target);
        flag[target] = true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k){
                break;
            }
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left and !flag[node->left]){
                    flag[node->left] = true;
                    q.push(node->left);
                }
                if(node->right and !flag[node->right]){
                    flag[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] and !flag[parent[node]]){
                    flag[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int> res;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
        
        
    }
};