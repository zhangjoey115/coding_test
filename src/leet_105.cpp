
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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int size = preorder.size();
    if (size < 1) return nullptr;

    int root_val = preorder[0];
    TreeNode* root = new TreeNode(root_val);

    vector<int> preorder_left, preorder_right;
    vector<int> inorder_left, inorder_right;
    auto i_root = find(inorder.begin(), inorder.end(), root_val);
    copy(inorder.begin(), i_root, back_inserter(inorder_left));
    copy(i_root + 1, inorder.end(), back_inserter(inorder_right));

    int size_left = inorder_left.size();
    copy(preorder.begin() + 1, preorder.begin() + 1 + size_left,
         back_inserter(preorder_left));
    copy(preorder.begin() + 1 + size_left, preorder.end(),
         back_inserter(preorder_right));
    // vector<int>::iterator pre_max = preorder.begin();
    // for (auto v : inorder_left) {
    //   auto i = find(preorder.begin(), preorder.end(), v);
    //   if (i > pre_max) pre_max = i;
    // }
    // copy(preorder.begin(), pre_max + 1, back_inserter(preorder_left));
    // copy(pre_max + 1, preorder.end(), back_inserter(preorder_right));

    TreeNode* left = buildTree(preorder_left, inorder_left);
    TreeNode* right = buildTree(preorder_right, inorder_right);
    root->left = left;
    root->right = right;

    return root;
  }
};

int main() {
  // struct TreeNode node[7];
  // node[0].val = 1;
  // node[0].left = &node[1];
  // node[0].right = &node[2];
  // node[1].val = 2;
  // // node[1].left = &node[3];
  // node[1].right = &node[4];
  // node[2].val = 2;
  // // node[2].left = &node[5];
  // node[2].right = &node[6];
  // node[3].val = 3;
  // node[4].val = 3;
  // node[5].val = 4;
  // node[6].val = 3;
  vector<int> preorder{3, 9, 20, 15, 7};
  vector<int> inorder{9, 3, 15, 20, 7};

  Solution s;
  auto res = s.buildTree(preorder, inorder);
  // cout << res << endl;

  return 0;
}
