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
    void flatten(TreeNode* root) {
        
        stack<TreeNode*> s;
        s.push(root);
        if(root == NULL){
            return;
        }
        while(!s.empty()){
            
            TreeNode* curr = s.top();
            s.pop();
            
            if(curr->right != NULL){
                s.push(curr->right);
            }
            if(curr->left != NULL){
                s.push(curr->left);
            }
            if(!s.empty()){
                curr->right = s.top();
                curr->left = NULL;
            }
        
            
        }
        
        
    }
};