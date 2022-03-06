
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    map<char, long> char_map;
    long len_sub_max = 0;
    long i_start = 0;
    long i_end = 0;
    long i_start_max = 0;
    long i_end_max = 0;
    long len = s.length();
    if (len <= 0) {
      return 0;
    }
    char cur_char;
    const char* s_char = s.data();
    for (long i = 0; i < len; i++) {
      i_end = i;
      cur_char = s_char[i];
      auto f_res = char_map.find(cur_char);
      if (f_res == char_map.end()) {
        char_map.insert(make_pair(cur_char, i));
      } else {
        if (f_res->second >= 0) {  // duplicated, renew start index
          i_start = char_map[cur_char] + 1;
          char_map[cur_char] = i;
          for (auto it = char_map.begin(); it != char_map.end(); it++) {
            if (it->second < i_start) {
              it->second = -1;
            }
          }
        } else {
          f_res->second = i;  // not duplicated
        }
      }

      if (i_end - i_start > len_sub_max) {
        len_sub_max = i_end - i_start;
        i_start_max = i_start;
        i_end_max = i_end;
      }
    }
    return len_sub_max + 1;
  }
};

int main() {
  string str = "abcabcbb";

  Solution s;
  auto res = s.lengthOfLongestSubstring(str);
  cout << res << endl;

  return 0;
}
