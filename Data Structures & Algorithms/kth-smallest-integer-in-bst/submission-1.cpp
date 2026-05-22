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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->left)
            {
                TreeNode* pred = cur->left;
                while(pred->right && pred->right != cur) //pred最後會到cur之前繼，就算之前已將pred->right連至cur也會停
                {
                    pred = pred->right;
                }
                if(pred->right != cur)//pred尚未建立後繼pointer
                {
                    pred->right = cur;
                    cur = cur->left;
                }
                else // pred已連接 表左子樹已scan完 輪到root
                {
                    k--;
                    if(k == 0) return cur->val;
                    cur = cur->right;
                }
            }
            else //無左子樹 輪到root
            {
                k--;
                if(k == 0) return cur->val;
                cur = cur->right;
            }
        }
        return -1;
    }
};
