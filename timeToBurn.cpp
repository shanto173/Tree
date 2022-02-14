/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp,BinaryTreeNode<int>* target){
    map<BinaryTreeNode<int>*,bool> vis;
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    vis[target] = 1;
	int maxi = 0;
    while(!q.empty()){
        int n = q.size();
        int f1 = 0;
        for(int i=0;i<n;i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(node->left and !vis[node->left]){
                vis[node->left] = 1;
                q.push(node->left);
                f1 = 1;
            }
            if(node->right and !vis[node->right]){
                vis[node->right] = 1;
                q.push(node->right);
                f1 = 1;
            }
            if(mpp[node] and !vis[mpp[node]]){
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
                f1 = 1;
            }
        }
        if(f1){
            maxi++;
        }
    }
    return maxi;
}


BinaryTreeNode<int>* bfsToMapParent(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mpp,
                                    int start){
    queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int>* res;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if(node->data == start) res = node;
        if(node->left){
            mpp[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mpp;
    BinaryTreeNode<int>* target = bfsToMapParent(root,mpp,start);
    int maxi = findMaxDistance(mpp,target);
    return maxi;
}
