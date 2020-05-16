// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

// 你可以假设数组中不存在重复的元素。

// 你的算法时间复杂度必须是 O(log n) 级别。

//还是用二分法，
//先找到旋转元素，然后可以知道target在哪个区域，然后再在这个区域使用二分查找

#include "search.h"

Solution::Solution() {}

Solution::~Solution() {}

int Solution::search(std::vector<int>& nums, int target){
  int low = 0, high = nums.size() - 1, index = -1;
  int mid;
  while(low <= high){
    mid = (low + high) / 2;
    if(nums[mid] == target){
      index = mid;
      break;
    }
    // 先判断有序，根据nums[0]和nums[mid]比较判断哪边有序
    if(nums[0] <= nums[mid]){
      if(nums[low] <= target && nums[mid] > target){
        high = mid - 1;
      }
      else{
        low = mid + 1;
      }
    }
    else{
      if(nums[mid] < target && nums[high] >= target){
        low = mid + 1;
      }
      else{
        high = mid - 1;
      }
    }
  }
  return index;
}