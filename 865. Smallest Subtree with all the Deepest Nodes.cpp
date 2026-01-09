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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depthAndNodeWithEqualDepth(root).second;
    }

    pair<int, TreeNode*> depthAndNodeWithEqualDepth(TreeNode* node) {
        if(node==NULL) {
            return {0, NULL};
        }
        auto left = depthAndNodeWithEqualDepth(node->left);
        auto right = depthAndNodeWithEqualDepth(node->right);

        if(left.first==right.first) {
            return {left.first+1, node};
        } else if (left.first>right.first) {
            return {left.first+1, left.second};
        } else {
            return {right.first+1, right.second};
        }
    }
};
