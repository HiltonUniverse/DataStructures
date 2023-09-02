#pragma once

#include <QDebug>

class MergeTwoSortedLists
{
public:
    //-----------------------------------
    struct ListNode
    {
      int val;
      ListNode* next;

      ListNode()
          : val(0)
          , next(nullptr)
      {
      }

      ListNode(int val)
          : val(val)
          , next(nullptr)
      {
      }

      ListNode(int val, ListNode* next)
          : val(val)
          , next(next)
      {
      }
    };

    //-----------------------------------
    //Not the best approach:
    //Time complexity : O(l1) + O(l2) + O((l1 + l2) * log(l1 + l2)) + O(l1 + l2) = O((l1 + l2) * log(l1 + l2))
    //Space complexity : O(l1 + l2)
    ListNode* mergeTwoListsOkVersion(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr)
        {
            return l2;
        }

        if(l2 == nullptr)
        {
            return l1;
        }

        std::vector<int> values;
        ListNode* current_node = l1;
        while(current_node != nullptr) //O(l1)
        {
            values.push_back(current_node->val);
            current_node = current_node->next;
        }

        current_node = l2;
        while(current_node != nullptr) //O(l2)
        {
            values.push_back(current_node->val);
            current_node = current_node->next;
        }

        std::sort(values.begin(), values.end()); //(n log n), n = O(l1) + O(l2)

        ListNode* dummy = new ListNode();
        current_node = dummy;
        for(int i : values)  //O(n) = O(l1 + l2)
        {
            ListNode* new_node = new ListNode(i);
            current_node->next = new_node;
            current_node = new_node;
        }

        return dummy->next;
    }

    //-----------------------------------
    //Better version | But performance wise they take almost same amount of time and same amount of memory!
    //However when the input size becomes really large, the difference will show. This version will do much better.
    //Time complexity : O(l1 + l2)
    //Space complexity : O(1);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
        }

        if(l1 != nullptr)
        {
            current->next = l1;
        }

        if(l2 != nullptr)
        {
            current->next = l2;
        }

        return dummy->next;
    }

    //-----------------------------------
    void print(ListNode* list)
    {
        ListNode* current = list;
        while(current != nullptr)
        {
            qWarning() << current->val;
            current = current->next;
        }
    }
};


namespace test
{
    using ListNode = MergeTwoSortedLists::ListNode;

    void MergeTwoSortedListsTests()
    {
        //Create first linked list
        ListNode* list1_head = nullptr;
        ListNode* list1_one = new ListNode(1);
        ListNode* list1_two = new ListNode(2);
        ListNode* list1_three = new ListNode(4);
        list1_head = list1_one;
        list1_one->next = list1_two;
        list1_two->next = list1_three;

        //create second linked list
        ListNode* list2_head = nullptr;
        ListNode* list2_one = new ListNode(1);
        ListNode* list2_two = new ListNode(3);
        ListNode* list2_three = new ListNode(4);
        list2_head = list2_one;
        list2_one->next = list2_two;
        list2_two->next = list2_three;

        //merge them and print them
        MergeTwoSortedLists sorted_lists;
        sorted_lists.print(sorted_lists.mergeTwoLists(list1_head, list2_head)); //expected output: 1 1 2 3 4 4
    }
}
