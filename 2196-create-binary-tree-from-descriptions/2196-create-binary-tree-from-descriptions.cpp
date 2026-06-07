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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> childs;
        unordered_map<int, TreeNode*> nodes;

        for(auto desc: descriptions){
            int p = desc[0], c = desc[1], pos = desc[2];
            childs.insert(c);
            TreeNode* parent, *child;
            if(nodes.count(p))
                parent = nodes[p];
            else{
                parent = new TreeNode(p);
                nodes[p] = parent;
            }
            if(nodes.count(c)){
                child = nodes[c];
            }
            else{
                child = new TreeNode(c);
                nodes[c] = child;
            }
            if(pos){
                parent -> left = child;
            }else{
                parent -> right = child;
            }
        }
        for(auto desc:descriptions){
            if(childs.count(desc[0]) == 0){
                return nodes[desc[0]];
            }
        }
        return nullptr;
    }
};