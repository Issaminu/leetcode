#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
    unordered_set<int> set;
    for (int num : nums) {
      auto result = set.insert(num);
      if (!result.second) {
        return num;
      }
    }
    return nums.back(); // We'll never reach here, so `nums.back()` is just to make clangd shut up
  }
};