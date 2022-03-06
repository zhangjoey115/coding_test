
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search_array(vector<int>& nums, int i_start, int i_stop, int num) {
  int res = -1;

  auto it_begin = nums.begin() + i_start;
  auto it_end = nums.begin() + i_stop;
  auto it_find = find(it_begin, it_end, num);
  if (it_find != it_end) {
    res = it_find - it_begin;
    res += i_start;
  }

  return res;
}

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> nums_org = nums;
    sort(nums.begin(), nums.end());

    int size = nums.size();
    int size_m = (int)(size / 2);
    int f1, f2;
    for (int i = 0; i < size; i++) {
      f1 = i;
      int err = target - nums[i];

      // special case
      if (err == nums[i]) {  // target = 2*num[i]
        if (nums[i + 1] == nums[i]) {
          f2 = i + 1;
          break;
        } else {
          continue;
        }
      } else if (err == nums[size_m]) {
        f2 = size_m;
        break;
      }
      // two devide search
      else {
        int i_start, i_stop;
        if (err < nums[size_m]) {
          i_start = 0;
          i_stop = size_m;
        } else {
          i_start = size_m + 1;
          i_stop = size;
        }
        int res = search_array(nums, i_start, i_stop, err);
        if (res > 0) {
          f2 = res;
          break;
        } else {
          continue;
        }
      }
    }

    if (nums[f1] == nums[f2]) {
      auto first = find(nums_org.begin(), nums_org.end(), nums[f1]);
      f1 = first - nums_org.begin();
      f2 = find(first + 1, nums_org.end(), nums[f2]) - nums_org.begin();
    } else {
      f1 = find(nums_org.begin(), nums_org.end(), nums[f1]) - nums_org.begin();
      f2 = find(nums_org.begin(), nums_org.end(), nums[f2]) - nums_org.begin();
    }

    vector<int> res{f1, f2};
    return res;
  }
};

int main() {
  vector<int> nums{5, 7, 5, 9, 6};
  int target = 10;
  // cout << "nums = " << nums << endl;
  cout << "target = " << target << endl;

  Solution s;
  vector<int> res = s.twoSum(nums, target);
  cout << res[0] << ", " << res[1] << endl;

  return 0;
}
