
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
// #include <pair>
#include <queue>

using namespace std;

class Solution {
 public:
  bool check_sub(vector<vector<char>>& board, vector<int>& start_index,
                 string word, int word_index, vector<vector<int>>& map_close) {
    if (word_index >= word.size()) return true;

    int row = board.size();
    int col = board[0].size();
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    if (start_index[0] + 1 < row) down = true;
    if (start_index[0] - 1 >= 0) up = true;
    if (start_index[1] + 1 < col) right = true;
    if (start_index[1] - 1 >= 0) left = true;
    if (left && map_close[start_index[0]][start_index[1] - 1] != 1 &&
        board[start_index[0]][start_index[1] - 1] == word[word_index]) {
      int new_r = start_index[0];
      int new_c = start_index[1] - 1;
      map_close[new_r][new_c] = 1;
      vector<int> start_index_new({new_r, new_c});
      int word_index_new = word_index + 1;
      bool ret =
          check_sub(board, start_index_new, word, word_index_new, map_close);
      if (ret == true)
        return true;
      else
        map_close[new_r][new_c] = 0;
    }
    if (right && map_close[start_index[0]][start_index[1] + 1] != 1 &&
        board[start_index[0]][start_index[1] + 1] == word[word_index]) {
      int new_r = start_index[0];
      int new_c = start_index[1] + 1;
      map_close[new_r][new_c] = 1;
      vector<int> start_index_new({new_r, new_c});
      int word_index_new = word_index + 1;
      bool ret =
          check_sub(board, start_index_new, word, word_index_new, map_close);
      if (ret == true)
        return true;
      else
        map_close[new_r][new_c] = 0;
    }
    if (up && map_close[start_index[0] - 1][start_index[1]] != 1 &&
        board[start_index[0] - 1][start_index[1]] == word[word_index]) {
      int new_r = start_index[0] - 1;
      int new_c = start_index[1];
      map_close[new_r][new_c] = 1;
      vector<int> start_index_new({new_r, new_c});
      int word_index_new = word_index + 1;
      bool ret =
          check_sub(board, start_index_new, word, word_index_new, map_close);
      if (ret == true)
        return true;
      else
        map_close[new_r][new_c] = 0;
    }
    if (down && map_close[start_index[0] + 1][start_index[1]] != 1 &&
        board[start_index[0] + 1][start_index[1]] == word[word_index]) {
      int new_r = start_index[0] + 1;
      int new_c = start_index[1];
      map_close[new_r][new_c] = 1;
      vector<int> start_index_new({new_r, new_c});
      int word_index_new = word_index + 1;
      bool ret =
          check_sub(board, start_index_new, word, word_index_new, map_close);
      if (ret == true)
        return true;
      else
        map_close[new_r][new_c] = 0;
    }
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> map_close(row, vector<int>(col, 0));
    bool ret = false;
    for (auto i = board.begin(); i != board.end(); i++) {
      int start_j = 0;
      while (1) {
        auto j = find(i->begin() + start_j, i->end(), word[0]);
        if (j != i->end()) {
          int r = i - board.begin();
          int c = j - i->begin();
          vector<int> start_index({r, c});
          map_close[r][c] = 1;
          int word_index = 1;
          bool ret = check_sub(board, start_index, word, word_index, map_close);
          map_close[r][c] = 0;
          if (ret == true)
            return true;
          else
            start_j = j - i->begin() + 1;
        } else {
          break;
        }
      }
    }
    return false;
  }
};

int main() {
  // vector<vector<char>> board{
  //     {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  // string word("SEE");
  // vector<vector<char>> board{{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C',
  // 'D'}};
  // string word("AAB");
  vector<vector<char>> board{{'A', 'A', 'S'}, {'S', 'E', 'E'}, {'E', 'S', 'A'}};
  string word("AES");

  Solution s;
  auto res = s.exist(board, word);
  cout << res << endl;

  return 0;
}
