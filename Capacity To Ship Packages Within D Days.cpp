#include <vector>      
#include <numeric>     
#include <algorithm>   

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = std::accumulate(weights.begin(), weights.end(), 0);

        while (l < r) {
            const int m = (l + r) / 2;
            if (shipDays(weights, m) <= days)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    int shipDays(const std::vector<int>& weights, int shipCapacity) {
        int days = 1;
        int capacity = 0;
        for (const int weight : weights)
            if (capacity + weight > shipCapacity) {
                ++days;
                capacity = weight;
            } else {
                capacity += weight;
            }
        return days;
    }
};
