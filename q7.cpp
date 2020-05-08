/*
  In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

  Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

  We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

  Return true if and only if the nodes corresponding to the values x and y are cousins.
*/

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int levelx=INT_MIN, levely=INT_MIN, px, py, outlev=0, inlev;
        while(!q.empty()){
            int qsize = q.size();
            inlev = 0;
            for(int i=0; i<qsize; i++){
                TreeNode* temp = q.front();
                if(temp){
                    if(temp->val==x){
                        levelx = outlev;
                        px = inlev;
                    }
                    if(temp->val==y){
                        levely = outlev;
                        py = inlev;
                    }
                    q.push(temp->left);
                    q.push(temp->right);
                }
                inlev++;
                q.pop();
            }
            outlev++;
            if(levelx >=0 && levely >= 0)
                break;
        }
        if(levelx != levely)
            return false;
        return (abs(px-py)!=1 || (px+py)%4 != 1);
    }
    
};
