#include <vector>

class Solution {
public:
  Solution();
  ~Solution();
  void nextPermutation(std::vector<int>& nums);
  void swap(std::vector<int>& nums, int i, int j);
  void reverse(std::vector<int>& nums, int a, int b);
};