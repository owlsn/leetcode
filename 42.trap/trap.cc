// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

// 示例:

// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6

//和之前的判断最大储水量的题目有类似之处
//使用双指针
#include "trap.h"

Solution::Solution() {}

Solution::~Solution() {}

int Solution::trap(std::vector<int>& height){
  int max = 0;
  if(!height.size()){
    return max;
  }
  int left = 0, right = height.size() - 1;
  int left_max = height[left], right_max = height[right];
  while(right > left){
    if(height[left] < height[right]){
      if(height[left] > left_max){
        left_max = height[left];
      }
      else{
        max += left_max - height[left];
      }
      ++ left;
    }
    else{
      if(height[right] > right_max){
        right_max = height[right];
      }
      else{
        max += right_max - height[right];
      }
      -- right;
    }
  }
  return max;
}
