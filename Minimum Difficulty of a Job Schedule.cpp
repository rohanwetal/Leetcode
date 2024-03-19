class Solution {
 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    const int n = jobDifficulty.size();
    if (n < d)
      return -1;

    vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
      for (int k = 1; k <= d; ++k) {
        int maxDifficulty = 0;                 
        for (int j = i - 1; j >= k - 1; --j) {  
          maxDifficulty = max(maxDifficulty, jobDifficulty[j]);  
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + maxDifficulty);
        }
      }

    return dp[n][d];
  }
};
