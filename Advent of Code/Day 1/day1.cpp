#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ifstream MyReadFile("day1.csv");
  string myText;
  int temp = 0, biggestThree = 0, i = 0;
  vector<int> topThree(3);
  while (getline(MyReadFile, myText))
  {
    if (isalnum(myText[0]))
    {
      temp += stoi(myText);
      if (i == 0)
      {
        topThree[0] = temp;
      }
      else if (i == 1)
      {
        topThree[1] = temp;
      }
      else if (i == 2)
      {
        topThree[2] = temp;
      }
    }
    if (!isalnum(myText[0]) || MyReadFile.peek() == EOF)
    {
      if (temp >= topThree[2])
      {
        topThree[0] = max(topThree[0], topThree[1]);
        topThree[1] = max(topThree[2], topThree[1]);
        topThree[2] = temp;
      }
      else if (temp >= topThree[1])
      {
        topThree[0] = max(topThree[1], topThree[0]);
        topThree[1] = temp;
      }
      else if (temp > topThree[0])
      {
        topThree[0] = temp;
      }
      temp = 0;
    }
    i++;
  }
  cout << topThree[0] + topThree[1] + topThree[2];
}