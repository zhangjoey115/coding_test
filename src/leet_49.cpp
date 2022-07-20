
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
// #include <pair>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> result;
    for (auto& str : strs) {
      string str_t(str);
      // str_t.sort();
      sort(str_t.begin(), str_t.end());
      if (result.find(str_t) == result.end()) {
        // pair<string, vector<string>> pr(str_t, vector<string>({str}));
        result.insert(make_pair(str_t, vector<string>({str})));
      } else {
        auto& arr = result[str_t];
        arr.push_back(str);
      }
    }
    vector<vector<string>> result_vec;
    if (result.size() <= 0) {
      result_vec.push_back(vector<string>({""}));
      return result_vec;
    }
    for (auto& vec : result) {
      result_vec.emplace_back(move(vec.second));
    }
    return result_vec;
  }
};

int main() {
  // vector<string> strs = {"abc", "tea", "ate", "bat"};
  vector<string> strs;

  Solution s;
  auto res = s.groupAnagrams(strs);
  // cout << res << endl;

  return 0;
}
