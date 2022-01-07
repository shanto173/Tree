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
    
    int maxSum(TreeNode* root,int& mx){
        if(root == NULL){
            return 0;
        }
        int lS = max(0,maxSum(root->left,mx));
        int rS = max(0,maxSum(root->right,mx));        
        mx = max(mx,root->val+lS+rS);
     
        return root->val+max(lS,rS);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int mx = INT_MIN;
        
        maxSum(root,mx);
        
        return mx;

    }
};