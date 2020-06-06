#include <vector>
#include <unordered_map>

class Solution {
public:
  Solution() = default;
  ~Solution() = default;
  std::vector<std::vector<int> > permute(std::vector<int>& nums);
  void backtrace(std::vector<std::vector<int> >& res, std::unordered_map<int, bool>& used, int depth, std::vector<int>& nums, std::vector<int>& temp);
};