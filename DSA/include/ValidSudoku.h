#pragma once

#include <QDebug>
#include <vector>
#include <unordered_set>

class ValidSudoku
{
public:
    /*
     * Time complexity: O(9^2) = 0(1)
     * Space complexity: 0(9*9) = 0(1)
    */
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        std::unordered_set<char> row_visited[9];
        std::unordered_set<char> col_visited[9];
        std::unordered_set<char> subgrid_visited[3][3];

        for(int i= 0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                char value = board[i][j];

                if(value != '.')
                {
                    if(row_visited[i].count(value)
                            || col_visited[j].count(value)
                            || subgrid_visited[i/3][j/3].count(value))
                    {
                        return false;
                    }

                    row_visited[i].insert(value);
                    col_visited[j].insert(value);
                    subgrid_visited[i/3][j/3].insert(value);
                }
            }
        }

        return true;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    //-----------------------------------
    void isValidSudokuTest()
    {
        ValidSudoku valid_sudoku;

        std::vector<std::vector<char>> board_one{{'5','3','.','.','7','.','.','.','.'},
                                                 {'6','.','.','1','9','5','.','.','.'},
                                                 {'.','9','8','.','.','.','.','6','.'},
                                                 {'8','.','.','.','6','.','.','.','3'},
                                                 {'4','.','.','8','.','3','.','.','1'},
                                                 {'7','.','.','.','2','.','.','.','6'},
                                                 {'.','6','.','.','.','.','2','8','.'},
                                                 {'.','.','.','4','1','9','.','.','5'},
                                                 {'.','.','.','.','8','.','.','7','9'}};
        //must be TRUE
        qWarning() << "BOARD ONE: " << valid_sudoku.isValidSudoku(board_one);

        std::vector<std::vector<char>> board_two{{'8','3','.','.','7','.','.','.','.'},
                                                 {'6','.','.','1','9','5','.','.','.'},
                                                 {'.','9','8','.','.','.','.','6','.'},
                                                 {'8','.','.','.','6','.','.','.','3'},
                                                 {'4','.','.','8','.','3','.','.','1'},
                                                 {'7','.','.','.','2','.','.','.','6'},
                                                 {'.','6','.','.','.','.','2','8','.'},
                                                 {'.','.','.','4','1','9','.','.','5'},
                                                 {'.','.','.','.','8','.','.','7','9'}};
        //must be FALSE
        qWarning() << "BOARD TWO: " << valid_sudoku.isValidSudoku(board_two);
    }
}
