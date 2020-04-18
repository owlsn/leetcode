#include <string>

class Solution {
 private:
 public:
  Solution();
  ~Solution();
  bool isMatch(std::string s, std::string p);
  bool dp(const std::string s, const std::string p, int i, int j, std::vector<std::vector<int> >& index, std::vector<std::vector<int> >& memo);
};