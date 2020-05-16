// 编写一个程序，通过已填充的空格来解决数独问题。

// 一个数独的解法需遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
// 空白格用 '.' 表示。

// Note:

// 给定的数独序列只包含数字 1-9 和字符 '.' 。
// 你可以假设给定的数独只有唯一解。
// 给定数独永远是 9x9 形式的。

//使用回溯法，递归实现回溯法
#include "solveSudoku.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

void Solution::solveSudoku(std::vector<std::vector<char> >& board){
  std::vector<std::vector<bool> > row(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool> > col(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool> > table(9, std::vector<bool>(9, false));
  int temp;
  for(int i = 0; i < board.size(); ++ i){
    for(int j = 0; j < board[i].size(); ++ j){
      if(board[i][j] != '.'){
        temp = board[i][j] - '1';
        row[i][temp] = true;
        col[j][temp] = true;
        table[(i / 3) * 3 + j / 3][temp] = true;
      }
    }
  }
  backtrace(board, row, col, table, 0, 0);
}

bool Solution::backtrace(std::vector<std::vector<char> >& board, std::vector<std::vector<bool> >& row,
 std::vector<std::vector<bool> >& col, std::vector<std::vector<bool> >& table, int i, int j){
  //  std::cout << "backtrace " << i << " " << j << std::endl;
  if(i > 8){
    return true;
  }
  else{
    if(board[i][j] == '.'){
      for(char k = '1'; k <= '9'; k ++){
        if(!row[i][k - '1'] && !col[j][k - '1'] && !table[(i / 3) * 3 + j / 3][k - '1']){
          row[i][k - '1'] = true;
          col[j][k - '1'] = true;
          table[(i / 3) * 3 + j / 3][k - '1'] = true;
          board[i][j] = k;
          // std::cout << "i:" << i << ",j:" << j << ",k:" << k << ",(i / 3) * 3 + j / 3:" << (i / 3) * 3 + j / 3 << std::endl;
          if(backtrace(board, row, col, table, i + (j + 1) / 9, (j + 1) % 9)){
            return true;
          };
          board[i][j] = '.';
          row[i][k - '1'] = false;
          col[j][k - '1'] = false;
          table[(i / 3) * 3 + j / 3][k - '1'] = false;
        }
      }
    }
    else{
      return backtrace(board, row, col, table, i + (j + 1) / 9, (j + 1) % 9);
    }
  }
  return false;
}