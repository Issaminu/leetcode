#include <unordered_set>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> set;
    ListNode *h = head;
    while (h) {
      auto result = set.insert(h);
      if (!result.second) { // Insert failed
        return true;
      }
      h = h->next;
    }
    return false;
  }
};