#include <vector>   // Include for std::vector
#include <algorithm> // Include for std::min and std::max

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0; // Handle empty matrix

        const int m = matrix.size();
        const int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        int maxLength = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                maxLength = std::max(maxLength, dp[i][j]);
            }

        return maxLength * maxLength;
    }
};
