#include "replaceElements.h"

std::vector<int> Solution::replaceElements(std::vector<int>& arr){
  std::vector<int> res(arr.size());
  res[arr.size() - 1] = -1;
  for(int i = arr.size() - 2; i >= 0 ; i--){
    res[i] = std::max(arr[i + 1], res[i + 1]);
  }
  return res;
}