
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
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    sort(nums.begin(), nums.end(),
         [](int num1, int num2) { return num1 > num2; });
    // min, max, num
    // vector<vector<int>> num_lists(1, vector<int>({nums[0], nums[0], 1}));
    int cur_len = 1;
    int max_len = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] == nums[i] - 1) {
        cur_len++;
      } else if (nums[i + 1] == nums[i]) {
        continue;
      } else {
        max_len = max(max_len, cur_len);
        cur_len = 1;
      }
    }
    max_len = max(max_len, cur_len);
    return max_len;
  }
};

int main() {
  vector<int> nums{100, 4, 200, 1, 3, 2, 0};
  // vector<int> nums{1, 2, 0, 1, 4, 5, 3};

  Solution s;
  auto res = s.longestConsecutive(nums);
  cout << res << endl;

  return 0;
}
