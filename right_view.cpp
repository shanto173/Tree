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
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root == NULL){
            return ans;
        }
        
        while(!q.empty()){
           vector<int> res;
            int n = q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->right != NULL){
                    q.push(node->right);
                }
                if(node->left != NULL){
                    q.push(node->left);
                }
                res.push_back(node->val);
            }
            ans.push_back(res[0]);
        }
        return ans;
        
    }
};