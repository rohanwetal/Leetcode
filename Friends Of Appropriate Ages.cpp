#include <vector>        // Include for std::vector
#include <unordered_map> // Include for std::unordered_map
#include <iostream>

class Solution {
 public:
  int numFriendRequests(std::vector<int>& ages);
  bool request(int ageA, int ageB); // Declare function prototype
};

int Solution::numFriendRequests(std::vector<int>& ages) {
  int ans = 0;
  std::unordered_map<int, int> count;

  for (const int age : ages)
    ++count[age];

  for (auto itA = count.begin(); itA != count.end(); ++itA) {
    int ageA = itA->first;
    int countA = itA->second;
    for (auto itB = count.begin(); itB != count.end(); ++itB) {
      int ageB = itB->first;
      int countB = itB->second;
      if (request(ageA, ageB) && ageA != ageB) {
        if (ageA == ageB)
          ans += countA * (countB - 1);
        else
          ans += countA * countB;
      }
    }
  }

  return ans;
}

bool Solution::request(int ageA, int ageB) {
  return !(ageB <= 0.5 * ageA + 7 || ageB > ageA || (ageA < 100 && ageB > 100)); // Corrected condition
}

int main() {
  std::vector<int> ages = {20, 30, 35, 40, 50}; // Sample ages
  Solution sol;
  std::cout << "Number of friend requests: " << sol.numFriendRequests(ages) << std::endl;
  return 0;
}
