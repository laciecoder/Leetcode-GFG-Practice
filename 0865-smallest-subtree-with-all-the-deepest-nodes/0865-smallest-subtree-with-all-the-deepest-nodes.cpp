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
    int solve(TreeNode* root, TreeNode* &temp, int depth, int& maxDepth){
        maxDepth = max(depth, maxDepth);
        if(!root)
            return depth;
        int left = solve(root -> left, temp, depth + 1, maxDepth);
        int right = solve(root -> right, temp, depth + 1, maxDepth);

        if(left == right && left == maxDepth){
            temp = root;
        }
        return max(left, right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* temp;
        int maxDepth = 0;
        solve(root, temp, 0, maxDepth);
        return temp;
    }
};