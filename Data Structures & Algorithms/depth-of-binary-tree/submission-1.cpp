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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLen = 0;
        stack<pair<TreeNode*,int>> s;
        s.push({root,1});
        while(!s.empty())
        {
            TreeNode* p = s.top().first;
            int height = s.top().second;
            s.pop();
            if(!p->left && !p->right) // *p is leaf
            {
                if(maxLen < height)
                {
                    maxLen = height;
                }
            }
            if(p->left) s.push({p->left,height + 1});
            if(p->right) s.push({p->right,height + 1});
        }
        return maxLen;       
    }
};
