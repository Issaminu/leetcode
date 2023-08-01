#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    int size = position.size();
    vector<pair<int, float>> cars;
    int result = 1;
    for (int i = 0; i < size; i++)
    {
      cars.push_back({position[i], (float)(target - position[i]) / speed[i]}); // car[i].second is the Time it takes to reach the target
    }
    sort(cars.begin(), cars.end(), [](const pair<int, float> &a, const pair<int, float> &b)
         { return a.first > b.first; });
    for (int i = 1; i < size; i++)
    {
      if (cars[i].second > cars[i - 1].second)
      {
        result++;
      }
      else
      {
        cars[i].second = cars[i - 1].second;
      }
    }
    return result;
  }
};