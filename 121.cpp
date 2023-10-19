#include <vector>
using namespace std;
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    if (prices.size() < 2)
    {
      return 0;
    }

    int i = prices[0];
    int biggestWin = 0;
    for (int j = 1; j < prices.size(); j++)
    {
      int currentDelta = prices[j] - prices[i];
      if (currentDelta > biggestWin)
      {
        biggestWin = currentDelta;
        continue;
      }
      else if (prices[j] < prices[i])
      {
        i = j;
      }
    }
    return biggestWin;
  }
};