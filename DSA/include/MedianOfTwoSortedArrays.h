#include <QDebug>


class MedianOfTwoSortedArrays
{
public:
    //Bruteforce solution
    //Time complexity : O(n1) + O(n2) + O(n log(n)) = O(n log(n)), n = n1 + n2.

    //Space complexity : O(n)

    //Runtime = 31ms, memory consumed: ~90MB
    double findMedianSortedArraysBruteForce(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int> median_vec;
        for(int i : nums1) //O(n1) , n1 = size of nums1
        {
            median_vec.push_back(i);
        }

        for(int i : nums2) //O(n2 ) , n2 = size of nums2
        {
            median_vec.push_back(i);
        }

        std::sort(median_vec.begin(), median_vec.end()); //O(n log(n)) , n = n1 + n2

        int median_vec_size = median_vec.size();
        if((median_vec_size % 2) == 0) //even
        {
            //we have 0-th index array so - 1 on the size is necessary.
            return (median_vec[(median_vec_size - 1)/2] + median_vec[(median_vec_size - 1)/2 + 1])/2.0;
        }
        else
        {
            return median_vec[(median_vec_size - 1)/ 2];
        }
    }

    //-----------------------------------
    //Time complexity: O(log(min(nums1 size, num2 size)))
    //This time complexity because we do the binary search on the array that is minimum = min(num1 size,num2 size).
    //Just imagine if you have 2 arrays one with 10k elements and another with 3 elements, binary search on the array
    //with 3 elements will be instant compared to the one with 10k elements.

    //Space complexity: O(1)

    //Runtime = 12 milliseconds, memory consumed: ~90MB | This runs 2x faster than bruteforce method.
    //On top bruteforce get's worse and worse with larger inputs while this will reach constant speed performace.
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        //Take array with short length as explained why in time complexity section
        if(nums2.size() < nums1.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        int left = 0;
        //For right we do not do size() - 1, we take the full size as we are dealing with partitioninig and that happens at the edge not in the middle of the number.
        //[1 2 3 | 4 5 6], here partition happens after element number 3 not in 2'nd index. We cannot split 3 in half.
        int right = nums1_size;

        while(left <= right)
        {
            int partition_x = left + (right - left)/2;
            int partition_y = (nums1_size + nums2_size + 1)/2 - partition_x;

            int max_left_x = partition_x == 0 ? INT_MIN : nums1[partition_x - 1];
            int max_left_y = partition_y == 0 ? INT_MIN : nums2[partition_y - 1];

            int max_right_x = partition_x == nums1_size ? INT_MAX : nums1[partition_x];
            int max_right_y = partition_y == nums2_size ? INT_MAX : nums2[partition_y];

            if(max_left_x <= max_right_y && max_left_y <= max_right_x)
            {
                if((nums1_size + nums2_size) % 2 == 0) //even number
                {
                    return (std::max(max_left_x, max_left_y) + std::min(max_right_x, max_right_y))/2.0;
                }
                else //odd number
                {
                    return std::max(max_left_x, max_left_y);
                }
            }
            else if(max_left_x > max_right_y) //we are too much to the right in the nums1 array, so we move right ptr to the left.
            {
                right = partition_x - 1;
            }
            else //we are too much to the left side of x becuase (max_left_y > max_right_x), move left prt to the right side.
            {
                left = partition_x + 1;
            }
        }

        return -1;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void medianOfTwoSortedArraysTests()
    {
        MedianOfTwoSortedArrays median;
        std::vector<int> num1{23,26,31,25};
        std::vector<int> num2{3,5,7,9,11,16};
    }
}
