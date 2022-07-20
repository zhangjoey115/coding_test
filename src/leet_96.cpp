
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> num_table(20, 0);
class Solution {
 public:
  int CalcSubNum(vector<int>& num_vec) {
    if (num_table[num_vec.size()] != 0) return num_table[num_vec.size()];

    int num_all = 0;
    vector<int> num_left, num_right;
    if (num_vec.size() <= 1) {
      num_table[num_vec.size()] = 1;
      return 1;
    }
    for (int i = 0; i < num_vec.size(); i++) {
      num_left.clear();
      num_right.clear();
      for (auto n : num_vec) {
        if (n < num_vec[i]) {
          num_left.push_back(n);
        } else if (n > num_vec[i]) {
          num_right.push_back(n);
        }
      }
      int num_l = CalcSubNum(num_left);
      int num_r = CalcSubNum(num_right);
      int num_t = num_l * num_r;
      num_all += num_t;
    }
    num_table[num_vec.size()] = num_all;
    return num_all;
  }

  int numTrees(int n) {
    vector<int> num_vec;
    for (int i = 0; i < n; i++) num_vec.push_back(i + 1);
    return CalcSubNum(num_vec);
  }
};

int main() {
  int n = 19;

  Solution s;
  auto res = s.numTrees(n);
  cout << res << endl;

  return 0;
}
