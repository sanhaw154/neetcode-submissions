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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* big = nullptr;
        TreeNode* small = nullptr;
        if(p->val < q->val)
        {
            big = q;
            small = p;
        }
        else
        {
            big = p;
            small = q;
        }
        TreeNode* start = root;
        while(start != nullptr)
        {
            int value = start->val;
            if( value < big->val && value < small->val )
            {
                start = start->right;
            }
            else if ( value > big->val && value > small->val )
            {
                start = start->left;
            }
            else
            {
                return start;
            }
        }
    }
};
