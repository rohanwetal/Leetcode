#include <vector> 
#include <algorithm>

class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        int ans = 0;

        std::sort(cost.begin(), cost.end()); 

        for (int i = 0; i < cost.size(); ++i)
            if (i % 3 != 2)
                ans += cost[i];

        return ans;
    }
};
