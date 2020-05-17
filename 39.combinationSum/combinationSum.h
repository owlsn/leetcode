#include <vector>

class Solution {
public:
  Solution();
  ~Solution();
  std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target);
  void backtrace(std::vector<int>& candidates, int start, int target, std::vector<std::vector<int> >& ret, std::vector<int>& l);
};