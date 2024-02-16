#include <vector> 
#include <algorithm> 

class Solution {
public:
    int longestCycle(std::vector<int>& edges) {
        int ans = -1;
        int time = 1;
        std::vector<int> timeVisited(edges.size());

        for (int i = 0; i < edges.size(); ++i) {
            if (timeVisited[i])
                continue;
            const int startTime = time;
            int u = i;
            while (u != -1 && !timeVisited[u]) {
                timeVisited[u] = time++;
                u = edges[u];  // Move to the next node.
            }
            if (u != -1 && timeVisited[u] >= startTime)
                ans = std::max(ans, time - timeVisited[u]);
        }

        return ans;
    }
};
