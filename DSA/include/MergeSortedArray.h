#pragma once

#include <QDebug>

class MergeSortedArray
{
public:
    //-----------------------------------
    //T : O(n log n), n = nums1 size + nums 2 size
    //S: O(1)
    void mergeLazyVersion(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        //basically copy nums2 values into the nums1 extra space.
        //and sort them.
        for(int i = 0; i < n; ++i)
        {
            nums1[m + i] = nums2[i];
        }

        std::sort(nums1.begin(), nums1.end());
    }

    //-----------------------------------
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int nums1_ptr = m - 1;
        int nums2_ptr = n - 1;
        int index_to_insert = nums1.size() - 1;

        while(nums1_ptr >= 0 && nums2_ptr >= 0)
        {
            if(nums1[nums1_ptr] > nums2[nums2_ptr])
            {
                nums1[index_to_insert] = nums1[nums1_ptr];
                --nums1_ptr;
            }
            else
            {
                nums1[index_to_insert] = nums2[nums2_ptr];
                --nums2_ptr;
            }
            --index_to_insert;
        }

        //At this point, if nums 2 ran out and nums1 still has elements to compare.
        //we don't need to do anything because it's already sorted correctly.
        //But that's not the case if nums 1 runs out and nums 2 remains. Nums 2 needs
        //to be copied over to nums1.
        while(nums2_ptr >= 0 )
        {
            nums1[index_to_insert] = nums2[nums2_ptr];
            --nums2_ptr;
            --index_to_insert;
        }
    }
};


namespace test
{
    void MergeSortedArrayTests()
    {
        std::vector<int> test{1,2,3,0,0,0};
        std::vector<int> test_2{2,5,6};

        MergeSortedArray merge;
        merge.mergeLazyVersion(test,3,test_2,3);
        qWarning() << test; //expected: 1 2 2 3 5 6
    }
}
