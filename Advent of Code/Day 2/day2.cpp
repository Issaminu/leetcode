#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int rock_paper_scissors(char opponent, char player)
{
  if (opponent == 'A') // Opponent is Rock
  {
    if (player == 'X') // Player is Rock
    {
      return 1 + 3;
    }
    else if (player == 'Y') // Player is Paper
    {
      return 2 + 6;
    }
    else // Player is Scissors
    {
      return 3 + 0;
    }
  }
  else if (opponent == 'B') // Opponent is Paper
  {
    if (player == 'X') // Player is Rock
    {
      return 1 + 0;
    }
    else if (player == 'Y') // Player is Paper
    {
      return 2 + 3;
    }
    else // Player is Scissors
    {
      return 3 + 6;
    }
  }
  else // Opponent is Scissors
  {
    if (player == 'X') // Player is Rock
    {
      return 1 + 6;
    }
    else if (player == 'Y') // Player is Paper
    {
      return 2 + 0;
    }
    else // Player is Scissors
    {
      return 3 + 3;
    }
  }
  cout << "DANGER DANGER" << endl;
  return 0;
}

int part2_rock_paper_scissors(char opponent, char player)
{
  if (opponent == 'A') // Opponent is Rock
  {
    if (player == 'X') // Player must lose, so he picks scissor
    {
      return 3 + 0;
    }
    else if (player == 'Y') // Player must draw, so he picks Rock
    {
      return 1 + 3;
    }
    else // Player is Scissors
    {
      return 2 + 6;
    }
  }
  else if (opponent == 'B') // Opponent is Paper
  {
    if (player == 'X') // Player must lose
    {
      return 1 + 0;
    }
    else if (player == 'Y') // Player is Paper
    {
      return 2 + 3;
    }
    else // Player is Scissors
    {
      return 3 + 6;
    }
  }
  else // Opponent is Scissors
  {
    if (player == 'X') // Player must lose
    {
      return 2 + 0;
    }
    else if (player == 'Y') // Player is Paper
    {
      return 3 + 3;
    }
    else // Player is Scissors
    {
      return 1 + 6;
    }
  }
  cout << "DANGER DANGER" << endl;
  return 0;
}

int main()
{
  ifstream MyReadFile("day2.csv");
  string myText;
  int result = 0;
  while (getline(MyReadFile, myText))
  {
    char opponent = myText[0];
    char player = myText[2];
    result += part2_rock_paper_scissors(opponent, player);
  }
  cout << result;
}
