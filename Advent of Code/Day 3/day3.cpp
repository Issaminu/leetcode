#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_set>

using namespace std;

int getPriorityOfItem(char c)
{
  if (isupper(c))
  {
    return c - 38;
  }
  else
  {
    return c - 96;
  }
  return 0;
}

int findIndex(const string &str, char c)
{
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] == c)
    {
      return i;
    }
  }
  return -1; // Character not found
}

int part_1()
{
  ifstream MyReadFile("day3.csv");
  string myText;
  int result = 0;
  while (getline(MyReadFile, myText))
  {
    int size = myText.size();
    int halfSize = size / 2;
    string firstHalf = myText.substr(0, halfSize);
    string secondHalf = myText.substr(halfSize);
    bool exit = false;
    for (int i = 0; i < halfSize; i++)
    {
      if (findIndex(secondHalf, firstHalf[i]) != -1)
      {
        result += getPriorityOfItem(firstHalf[i]);
        exit = true;
        break;
      }
      if (exit)
      {
        break;
      }
    }
  }
  cout << result << endl;
}

char getIntersection(const unordered_set<char> &set1, const unordered_set<char> &set2, const unordered_set<char> &set3)
{
  char intersection;

  for (const auto &element : set1)
  {
    if (set2.find(element) != set2.end() && set3.find(element) != set3.end())
    {
      intersection = element;
      break;
    }
  }

  return intersection;
}

int part_2()
{
  ifstream MyReadFile("day3.csv");
  string myText;
  int result = 0, i = 0;
  vector<string> threeElf;
  bool skip = false;
  while (getline(MyReadFile, myText))
  {
    threeElf.push_back(myText);
    i++;
    if (i == 3)
    {
      cout << threeElf.size() << endl;
      unordered_set<char> elf_one;
      for (char ch : threeElf[0])
      {
        elf_one.insert(ch);
      }
      unordered_set<char> elf_two;
      for (char ch : threeElf[1])
      {
        elf_two.insert(ch);
      }
      unordered_set<char> elf_three;
      for (char ch : threeElf[2])
      {
        elf_three.insert(ch);
      }

      const char badge = getIntersection(elf_one, elf_two, elf_three);
      result += getPriorityOfItem(badge);
      threeElf.clear();
      i = 0;
    }
  }
  cout << result << endl;
}

int main()
{
  part_1();
  part_2();
}