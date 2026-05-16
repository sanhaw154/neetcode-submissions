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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> t1;
        stack<TreeNode*> t2;
        t1.push(p);
        t2.push(q);
        while(!t1.empty() && !t2.empty() )
        {
            TreeNode* p1 = t1.top();
            TreeNode* p2 = t2.top();
            t1.pop();
            t2.pop();
            if( !p1 && !p2 )continue;
            else if( !(p1 && p2) ) return false;
            else if(p1->val != p2->val) return false;
             t1.push(p1->left);
             t1.push(p1->right);
             t2.push(p2->left);
             t2.push(p2->right);
        }
        if( !(t1.empty() && t2.empty()) ) return false;
        return true;
    }
};
