#pragma once

#include <QDebug>

class LinkedListCycle
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
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            if(fast == slow)
            {
                return true;
            }
            slow = slow->next;
        }

        return false;
    }
};


namespace test
{
    void LinkedListCycleTests()
    {
        using ListNode = LinkedListCycle::ListNode;
        //Create first linked list
        ListNode* list1_head = nullptr;
        ListNode* list1_one = new ListNode(1);
        ListNode* list1_two = new ListNode(2);
        ListNode* list1_three = new ListNode(4);
        ListNode* list1_four = new ListNode(5);
        list1_head = list1_one;
        list1_one->next = list1_two;
        list1_two->next = list1_three;
        list1_three->next = list1_four;
        list1_four->next = list1_two;  //creating cycle, 4 pointing to 2

        //create second linked list
        ListNode* list2_head = nullptr;
        ListNode* list2_one = new ListNode(1);
        ListNode* list2_two = new ListNode(3);
        ListNode* list2_three = new ListNode(4);
        list2_head = list2_one;
        list2_one->next = list2_two;
        list2_two->next = list2_three;

        //merge them and print them
        LinkedListCycle list;
        qWarning() << "FOUND CYCLE: " << list.hasCycle(list1_head);// TRUE
        qWarning() << "FOUND CYCLE: " << list.hasCycle(list2_head);// FALSE
    }
}
