#include <vector>

class Solution {
 public:
  int numPairsDivisibleBy60(std::vector<int>& time) {
    int ans = 0;
    std::vector<int> count(60);

    for (int t : time) {
      t %= 60;
      ans += count[(60 - t) % 60];
      ++count[t];
    }

    return ans;
  }
};
