// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

// 在杨辉三角中，每个数是它左上方和右上方的数的和。

// 示例:

// 输入: 5
// 输出:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

// 斜边和里面的数值分开写，动态规划

#include "generate.h"

std::vector<std::vector<int> > Solution::generate(int numRows){
  std::vector<std::vector<int> > res(numRows);
  for (int i = 0; i < numRows; i ++) {
    res[i] = std::vector<int>(i + 1, 0);
    res[i][0] = 1;
    res[i][i] = 1;
  }
  if (numRows <= 2){
    return res;
  }
  for(int i = 2; i < numRows; i ++){
    for(int j = 1; j < res[i].size() - 1; j ++){
      res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
    }
  }
  return res;
}