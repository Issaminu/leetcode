#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void part_one()
{
  ifstream MyReadFile("day4.csv");
  string myText;
  int result = 0;
  while (getline(MyReadFile, myText))
  {
    int first_range[] = {0, 0};
    int second_range[] = {0, 0};
    bool nowEndOfRange = false;
    bool nowEndOfRange2 = false;
    bool nowSecondElf = false;
    string firstElfStart;
    string firstElfEnd;
    string secondElfStart;
    string secondElfEnd;
    for (char c : myText)
    {
      if (c == ',')
      {
        nowSecondElf = true;
        continue;
      }
      else if (!nowSecondElf) // First Elf
      {
        if (c == '-')
        {
          nowEndOfRange = true;
          continue;
        }
        else if (!nowEndOfRange) // First Term of range of first elf
        {
          firstElfStart.push_back(c);
        }
        else // Second Term of range of first elf
        {
          firstElfEnd.push_back(c);
        }
      }
      else // Second Elf
      {
        if (c == '-')
        {
          nowEndOfRange2 = true;
          continue;
        }
        else if (!nowEndOfRange2) // First Term of range of second elf
        {
          secondElfStart.push_back(c);
        }
        else // Second Term of range of second elf
        {
          secondElfEnd.push_back(c);
        }
      }
    }
    first_range[0] = stoi(firstElfStart);
    first_range[1] = stoi(firstElfEnd);
    second_range[0] = stoi(secondElfStart);
    second_range[1] = stoi(secondElfEnd);
    // Case 1: the first range contains the second
    if (first_range[0] <= second_range[0] && first_range[1] >= second_range[1])
    {
      result++;
    }
    else if (second_range[0] <= first_range[0] && second_range[1] >= first_range[1]) // Case 2: the second range contains the first
    {
      result++;
    }
  }
  cout << result;
}

void part_two()
{
  ifstream MyReadFile("day4.csv");
  string myText;
  int result = 0;
  while (getline(MyReadFile, myText))
  {
    int first_range[] = {0, 0};
    int second_range[] = {0, 0};
    bool nowEndOfRange = false;
    bool nowEndOfRange2 = false;
    bool nowSecondElf = false;
    string firstElfStart;
    string firstElfEnd;
    string secondElfStart;
    string secondElfEnd;
    for (char c : myText)
    {
      if (c == ',')
      {
        nowSecondElf = true;
        continue;
      }
      else if (!nowSecondElf) // First Elf
      {
        if (c == '-')
        {
          nowEndOfRange = true;
          continue;
        }
        else if (!nowEndOfRange) // First Term of range of first elf
        {
          firstElfStart.push_back(c);
        }
        else // Second Term of range of first elf
        {
          firstElfEnd.push_back(c);
        }
      }
      else // Second Elf
      {
        if (c == '-')
        {
          nowEndOfRange2 = true;
          continue;
        }
        else if (!nowEndOfRange2) // First Term of range of second elf
        {
          secondElfStart.push_back(c);
        }
        else // Second Term of range of second elf
        {
          secondElfEnd.push_back(c);
        }
      }
    }
    first_range[0] = stoi(firstElfStart);
    first_range[1] = stoi(firstElfEnd);
    second_range[0] = stoi(secondElfStart);
    second_range[1] = stoi(secondElfEnd);
    if ((first_range[1] >= second_range[0] && first_range[0] <= second_range[0])) // <<- the magic happens here
    {
      result++;
    }
    else if (first_range[0] <= second_range[1] && first_range[1] >= second_range[0])
    {
      result++;
    }
  }

  cout << "result: " << result << endl;
}

int main()
{
  // part_one();
  part_two();
}