#include <QDebug>

#include <unordered_map>

class Search2DMatrix
{
public:
    // Time complexity: O(r * c) + O(log(r*c) =  O(r*c)!
    //space complexity: O(r * c)
        //r = row
        //c = column
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        std::vector<int> matrix_to_vec;
        //O(r * c)
        for(const auto& vec : matrix) //O(r)
        {
            matrix_to_vec.insert(matrix_to_vec.end(), vec.begin(), vec.end()); //O(c) for each insert
        }

        //apply binary search
        //O(log(matrix_to_vec.size())) = O(log(r*c))
        int left = 0;
        int right = matrix_to_vec.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(target == matrix_to_vec[mid])
            {
                return true;
            }

            if(target > matrix_to_vec[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }


    //-----------------------------------
    //Time complexity : O(log r) + O(log c); r = row length, c = column length
    //space complexity : O(1);
    bool searchMatrixImproved(std::vector<std::vector<int>>& matrix, int target)
    {
        int top_row = 0;
        int bottom_row = matrix.size() - 1;

        //with <, we won't enter the loop if top row and bottom row are pointing to the same row.
        while(top_row < bottom_row)
        {
            int mid = top_row + (bottom_row - top_row)/2;

            if(target > matrix[mid][matrix[mid].size() - 1])
            {
                top_row = mid + 1;
            }
            else if( target < matrix[mid][0])
            {
                bottom_row = mid - 1;
            }
            else
            {
                //we have found our row!
                top_row = mid;
                break;
            }
        }

        auto& vector_of_interest = matrix[top_row];

        int left = 0;
        int right = matrix[0].size() - 1;
        //here we are looking to find the taget exactly, so even after the left and right are equal, we will go in the loop and check the target exactly.
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(target == vector_of_interest[mid])
            {
               return true;
            }

            if(target > vector_of_interest[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void search2DMatrixTests()
    {
        Search2DMatrix search;
        std::vector<std::vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        qWarning() << search.searchMatrixImproved(matrix, 3);
        std::vector<std::vector<int>> matrix_2{{1}};
        qWarning() << search.searchMatrixImproved(matrix_2, 2);
        std::vector<std::vector<int>> matrix_3{{1},{3},{5}};
        qWarning() << search.searchMatrixImproved(matrix_3, 3);
    }
}
