
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

class Solution_Recursive {
 public:
  bool CheckLeftEqRight(TreeNode *left, TreeNode *right) {
    bool ret_all = false;
    bool ret_1 = false;
    bool ret_2 = false;
    if (left == nullptr && right == nullptr)
      return true;
    else if ((left == nullptr && right != nullptr) ||
             (left != nullptr && right == nullptr))
      return false;
    else if (left->val != right->val)
      return false;

    ret_1 = CheckLeftEqRight(left->left, right->right);
    ret_2 = CheckLeftEqRight(left->right, right->left);
    if (ret_1 == true && ret_2 == true)
      return true;
    else
      return false;
  }

  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    else
      return CheckLeftEqRight(root->left, root->right);
  }
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;

    int layer = 1;
    deque<TreeNode *> nodes_left, nodes_right;
    if (root->left != nullptr) nodes_left.push_back(root->left);
    if (root->right != nullptr) nodes_right.push_back(root->right);
    if (nodes_left.size() != nodes_right.size()) return false;

    vector<int> val_left;
    vector<int> val_right;
    while (nodes_left.size() > 0 && nodes_right.size() > 0) {
      val_left.clear();
      val_right.clear();

      int i_left = nodes_left.size();
      for (; i_left > 0; i_left--) {
        auto node = nodes_left.front();
        nodes_left.pop_front();

        if (node == nullptr) {
          val_left.push_back(-1);
          continue;
        } else {
          val_left.push_back(node->val);
          nodes_left.push_back(node->left);
          nodes_left.push_back(node->right);
          // if (node->left != nullptr) nodes_left.push_back(node->left);
          // if (node->right != nullptr) nodes_left.push_back(node->right);
        }
      }

      int i_right = nodes_right.size();
      for (; i_right > 0; i_right--) {
        auto node = nodes_right.front();
        nodes_right.pop_front();
        if (node == nullptr) {
          val_right.push_back(-1);
          continue;
        } else {
          val_right.push_back(node->val);
          nodes_right.push_back(node->left);
          nodes_right.push_back(node->right);
          // if (node->left != nullptr) nodes_right.push_back(node->left);
          // if (node->right != nullptr) nodes_right.push_back(node->right);
        }
      }

      if (val_left.size() != val_right.size())
        return false;
      else {
        reverse(val_right.begin(), val_right.end());
        for (int i = 0; i < val_left.size(); i++) {
          if (val_left[i] != val_right[i]) return false;
        }
      }
      layer++;
    }
    if (nodes_left.size() != nodes_right.size()) return false;
    return true;
  }
};

int main() {
  struct TreeNode node[7];
  node[0].val = 1;
  node[0].left = &node[1];
  node[0].right = &node[2];
  node[1].val = 2;
  // node[1].left = &node[3];
  node[1].right = &node[4];
  node[2].val = 2;
  // node[2].left = &node[5];
  node[2].right = &node[6];
  node[3].val = 3;
  node[4].val = 3;
  node[5].val = 4;
  node[6].val = 3;

  Solution s;
  auto res = s.isSymmetric(&node[0]);
  cout << res << endl;

  return 0;
}
