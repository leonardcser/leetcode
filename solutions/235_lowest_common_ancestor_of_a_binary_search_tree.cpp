// Time  complexity: O(n)
// Space complexity: O(1)
#include <cstddef>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        while (root) {
            // Both p and q are smaller than the root, so the LCA is on the left
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            // Both p and q are greater than the root, so the LCA is on the
            // right
            else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else {
                // LCA is found
                return root;
            }
        }

        return root;
    }
};
