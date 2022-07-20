
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
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
  bool CheckSubValid(TreeNode *node, int &sub_min, int &sub_max) {
    if (node->left == nullptr && node->right == nullptr) {
      sub_min = node->val;
      sub_max = node->val;
      return true;
    } else if (node->left == nullptr && node->right != nullptr) {
      int sub_min_t, sub_max_t;
      auto ret = CheckSubValid(node->right, sub_min_t, sub_max_t);
      sub_min = min(node->val, sub_min_t);
      sub_max = max(node->val, sub_max_t);
      if (ret == false || node->val >= sub_min_t)
        return false;
      else
        return true;
    } else if (node->left != nullptr && node->right == nullptr) {
      int sub_min_t, sub_max_t;
      auto ret = CheckSubValid(node->left, sub_min_t, sub_max_t);
      sub_min = min(node->val, sub_min_t);
      sub_max = max(node->val, sub_max_t);
      if (ret == false || node->val <= sub_max_t)
        return false;
      else
        return true;
    } else {
      bool ret_1 = false;
      bool ret_2 = false;
      int sub_min_l, sub_min_r;
      int sub_max_l, sub_max_r;
      ret_1 = CheckSubValid(node->left, sub_min_l, sub_max_l);
      ret_2 = CheckSubValid(node->right, sub_min_r, sub_max_r);
      sub_min = min(min(node->val, sub_min_l), sub_min_r);
      sub_max = max(max(node->val, sub_max_l), sub_max_r);
      if (ret_1 == true && ret_2 == true && sub_max_l < node->val &&
          node->val < sub_min_r)
        return true;
      else
        return false;
    }
  }

  bool isValidBST(TreeNode *root) {
    if (root == nullptr) return true;
    int sub_min, sub_max = 0;
    bool ret = CheckSubValid(root, sub_min, sub_max);
    // if(ret == true && root->val )
    return ret;
  }
};

int main() {
  struct TreeNode node[7];
  node[0].val = 5;
  node[0].left = &node[1];
  // node[0].right = &node[2];
  node[1].val = 2;
  node[1].left = &node[3];
  node[1].right = &node[4];
  node[2].val = 7;
  node[2].left = &node[5];
  node[2].right = &node[6];
  node[3].val = 1;
  node[4].val = 3;
  node[5].val = 6;
  node[6].val = 8;

  Solution s;
  auto res = s.isValidBST(&node[0]);
  cout << res << endl;

  return 0;
}
