#include <algorithm> // Include the necessary header for swap

// Definition for ListNode
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2)
      return list1 ? list1 : list2;
    if (list1->val > list2->val)
      std::swap(list1, list2); // Use std::swap instead of swap
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
};
