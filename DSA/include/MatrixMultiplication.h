#pragma once
#include <QDebug>

class MatrixMultiplication
{
public:
    //-----------------------------------
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b)
    {
        int row = a.size();
        int col = b[0].size();
        int row_2 = b.size();

        std::vector<std::vector<int>> result(row, std::vector<int>(col, 0));

        //this is the row in result
        for(int i = 0; i < row; ++i)
        {
            //this is the col in result
            for(int j = 0; j < col; ++j)
            {
                //this is the row in b
                for(int k = 0; k < row_2; ++k)
                {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        return result;
    }
};

namespace test
{
    void MatrixMultiplicationTests()
    {
        std::vector<std::vector<int>> a
        {
            {1,0,0},
            {-1,0,3},
        };

        std::vector<std::vector<int>> b
        {
            {7,0,0},
            {0,0,0},
            {0,0,1}
        };

        MatrixMultiplication multip;
        qWarning() << multip.multiply(a, b);
    }
}
