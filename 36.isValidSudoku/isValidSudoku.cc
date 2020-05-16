// 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

// 说明:
// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 给定数独序列只包含数字 1-9 和字符 '.' 。
// 给定数独永远是 9x9 形式的。

//根据规则判断即可
//一遍扫描，定义三个数组，记录已经存在的数，
//row[num][digit]=1代表第num行的digit数字已经有了
//column[num][digit]=1代表第num列的digit数字已经有了
//num = (row / 3) * 3 + column / 3表示第num个9ge
//table[num][digit]代表第num个9格的digit数字已经有了
#include "isValidSudoku.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

bool Solution::isValidSudoku(std::vector<std::vector<char> >& board){
  // init
  std::vector<std::vector<bool> > row(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool> > col(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool> > table(9, std::vector<bool>(9, false));
  int num = 0;
  int temp = 0;
  for(int i = 0; i < board.size(); i ++){
    for(int j = 0; j < board[i].size(); j ++){
      if(board[i][j] == '.'){
        continue;
      }
      temp = (char)board[i][j] - '1';
      num = (i / 3) * 3 + j / 3;
      // std::cout << "num:" << num << ",temp:" << temp << std::endl;
      if(row[i][temp] || col[j][temp] || table[num][temp]){
        return false;
      }
      row[i][temp] = true;
      col[j][temp] = true;
      table[num][temp] = true;
    }
  }
  return true;
}