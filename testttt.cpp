#include <vector>
#include <iostream>

using namespace std;
int largestElementInVector(vector<int> vec)
{
  int largest = 0;
  for (int item : vec)
  {
    largest = max(largest, item);
  }
  return largest;
}

int main()
{
  vector<int> vec = {1, 4, 6, 55, 0};
  cout << largestElementInVector(vec);
}