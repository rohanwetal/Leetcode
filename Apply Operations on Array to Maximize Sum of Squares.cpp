#include <vector> 

class Solution {
 public:
  int maxSum(std::vector<int>& nums, int k) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMaxBit = 30;
    int ans = 0;
    std::vector<int> minIndices(kMaxBit);
    std::vector<int> optimalNums(nums.size());

    for (const int num : nums)
      for (int i = 0; i < kMaxBit; ++i)
        if (num >> i & 1)
          optimalNums[minIndices[i]++] |= 1 << i;

    for (int i = 0; i < k; ++i)
      ans = (ans + static_cast<long>(optimalNums[i]) * optimalNums[i]) % kMod;

    return ans;
  }
};
