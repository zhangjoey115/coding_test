
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
  void fill_till_end(vector<vector<char>>& grid, int origin_i, int origin_j) {
    int m = grid.size();
    int n = grid[0].size();
    deque<int> edge{origin_i, origin_j};
    int node[2];
    while (!edge.empty()) {
      node[0] = edge.front();
      edge.pop_front();
      node[1] = edge.front();
      edge.pop_front();
      if (node[0] + 1 < m && grid[node[0] + 1][node[1]] == '1') {
        edge.emplace_back(node[0] + 1);
        edge.emplace_back(node[1]);
        grid[node[0] + 1][node[1]] = '0';
      }
      if (node[1] + 1 < n && grid[node[0]][node[1] + 1] == '1') {
        edge.emplace_back(node[0]);
        edge.emplace_back(node[1] + 1);
        grid[node[0]][node[1] + 1] = '0';
      }
      if (node[0] - 1 >= 0 && grid[node[0] - 1][node[1]] == '1') {
        edge.emplace_back(node[0] - 1);
        edge.emplace_back(node[1]);
        grid[node[0] - 1][node[1]] = '0';
      }
      if (node[1] - 1 >= 0 && grid[node[0]][node[1] - 1] == '1') {
        edge.emplace_back(node[0]);
        edge.emplace_back(node[1] - 1);
        grid[node[0]][node[1] - 1] = '0';
      }
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int iland = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          iland++;
          grid[i][j] = '0';
          fill_till_end(grid, i, j);
        }
      }
    }
    return iland;
  }
};

int main() {
  vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '1', '0', '0'},
                            {'0', '0', '1', '1', '1'}};
  // vector<int> nums{1, 2, 0, 1, 4, 5, 3};

  Solution s;
  auto res = s.numIslands(grid);
  cout << res << endl;

  return 0;
}
