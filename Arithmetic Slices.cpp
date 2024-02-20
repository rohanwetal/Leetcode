#include <vector>    
#include <numeric>   

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    const int n = nums.size();
    if (n < 3)
      return 0;

    std::vector<int> dp(
        n);  

    for (int i = 2; i < nums.size(); ++i)
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        dp[i] = dp[i - 1] + 1;

    return std::accumulate(dp.begin(), dp.end(), 0);
  }
};
