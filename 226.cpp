struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    TreeNode *node = root;
    reverseChildren(node);
    return root;
  }
  void reverseChildren(TreeNode *node) {
    if (!node) {
      return;
    }
    TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
    reverseChildren(node->left);
    reverseChildren(node->right);
  }
};