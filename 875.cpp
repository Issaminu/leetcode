#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int left = 1, right = getMax(piles);
    while (left < right)
    {
      int middle = (left + right) / 2;
      if (canKokoEatAll(piles, h, middle))
      {
        right = middle; // Reduce speed
      }
      else
      {
        left = middle + 1; // Increase speed
      }
    }
    return right; // Or left, same thing
  }
  int getMax(const vector<int> &array)
  {
    int maximum = 0;
    for (const int val : array)
    {
      maximum = max(val, maximum);
    }
    return maximum;
  }
  int canKokoEatAll(vector<int> &piles, int maximumHoursAllowed, int currentSpeed)
  {
    int currentTimeSpent = 0;
    for (int pile : piles)
    {
      currentTimeSpent += ceil(static_cast<double>(pile) / currentSpeed);
    }
    return currentTimeSpent <= maximumHoursAllowed;
  }
};