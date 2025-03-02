#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    unordered_set<string> seen;

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] != '.') {
          string row = to_string(board[i][j]) + " found in row " + to_string(i);
          string col = to_string(board[i][j]) + " found in col " + to_string(j);
          string box = to_string(board[i][j]) + " found in box " +
                       to_string(i / 3) + "-" + to_string(j / 3);

          if (seen.find(row) != seen.end() || seen.find(col) != seen.end() ||
              seen.find(box) != seen.end()) {
            return false;
          }

          seen.insert(row);
          seen.insert(col);
          seen.insert(box);
        }
      }
    }

    return true;
  }
};
