#include <vector>
#include <algorithm>
#include <stack>
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
      float time = (float)(target - position[i]) / speed[i];
      cars.push_back({position[i], time});
    }
    sort(cars.begin(), cars.end(), [](const pair<int, float> &a, const pair<int, float> &b)
         { return a.first > b.first; });
    for (int i = 0; i < size - 1; i++)
    {
      if (cars[i].second < cars[i + 1].second)
      {
        result++;
      }
      else
      {
        cars[i + 1].second = cars[i].second;
      }
    }
    return result;
  }
};