#include <vector>
using namespace std;
class Solution
{
public:
  int result;
  int change(int amount, vector<int> &coins)
  {
    if (amount == 0)
    {
      return 1;
    }
    change_recursive(amount, coins, coins.size() - 1);
    return result;
  }
  void change_recursive(int amount, vector<int> &coins, int index)
  {

    if (index < 0)
    {
      return;
    }
    if (amount % coins[index] == 0)
    {
      result++;
    }
    int counter = 1;
    int remains = amount - coins[index] * counter;
    while (remains >= 0)
    {
      vector<int> subArray(coins.begin(), coins.end() - 1);
      change_recursive(remains, subArray, index - 1);
      counter++;
      remains = amount - coins[index] * counter;
    }
  }
};