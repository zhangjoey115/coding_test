
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums[0];
    }
    int prd = nums[0];
    int prd_max = nums[0];
  }
};

int main() {
  vector<int> nums{100, -4, 200, 1, 3, 2, 0};
  // vector<int> nums{1, 2, 0, 1, 4, 5, 3};

  Solution s;
  auto res = s.maxProduct(nums);
  cout << res << endl;

  return 0;
}
