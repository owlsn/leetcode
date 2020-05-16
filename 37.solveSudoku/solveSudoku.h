#include <vector>

class Solution {
public:
  Solution();
  ~Solution();
  void solveSudoku(std::vector<std::vector<char> >& board);
  bool backtrace(std::vector<std::vector<char> >& board, std::vector<std::vector<bool> >& row,
 std::vector<std::vector<bool> >& col, std::vector<std::vector<bool> >& table, int i, int j);
};