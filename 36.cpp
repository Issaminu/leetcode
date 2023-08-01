#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // The idea is to use an unordered_set and check if the number of non-empty cells in each row is equivalent to the size of the set of that row.
        // After going through all rows, we go through all columns.
        // And finally, we go through all 3x3 squares.

        bool isValid = true;

        // Row by row verification
        unordered_set<int> rowSet;
        int insertAttempts = 0;
        for (int i = 0; i < 9; i++)
        {
            rowSet.clear();
            insertAttempts = 0;
            for (int j = 0; j < 9; j++)
            {

                if (board[i][j] != '.')
                {
                    rowSet.insert(board[i][j]);
                    insertAttempts++;
                }
            }
            if (rowSet.size() != insertAttempts)
            {
                return false;
            }
        }

        // Col by col verification
        unordered_set<int> colSet;
        insertAttempts = 0;
        for (int i = 0; i < 9; i++)
        {
            colSet.clear();
            insertAttempts = 0;
            for (int j = 0; j < 9; j++)
            {

                if (board[j][i] != '.')
                {
                    colSet.insert(board[j][i]);
                    insertAttempts++;
                }
            }
            if (colSet.size() != insertAttempts)
            {
                return false;
            }
        }

        // Square by square verification
        unordered_set<int> squareSet;
        insertAttempts = 0;
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                squareSet.clear();
                insertAttempts = 0;
                for (int row = i; row < i + 3; ++row)
                {
                    for (int col = j; col < j + 3; ++col)
                    {
                        if (board[row][col] != '.')
                        {
                            squareSet.insert(board[row][col]);
                            insertAttempts++;
                        }
                    }
                }
                if (squareSet.size() != insertAttempts)
                {
                    return false;
                }
            }
        }
        return true;
    }
};