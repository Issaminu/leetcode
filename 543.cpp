#include <math.h>
using namespace std;
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
  int diameterOfBinaryTree(TreeNode *root) {
    TreeNode *node = root;
    int left = 0, right = 0;
    while (node) {
      left = findMaxDepth(node->left, left);
      right = findMaxDepth(node->right, right);
    }
  }

  int findMaxDepth(TreeNode *node, int depth) {
    if (!node) {
      return depth;
    }
    depth++;
    return max(findMaxDepth(node->left, depth),
               findMaxDepth(node->right, depth));
  }
};