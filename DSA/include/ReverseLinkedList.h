#pragma once

#include <QDebug>

struct ListNode
{
    int value;
    ListNode* next;

    ListNode()
        : value(0)
        , next(nullptr)
    {
    }

    ListNode(int data)
        : value(data)
        , next(nullptr)
    {
    }

    ListNode(int data, ListNode* node)
        : value(data)
        , next(node)
    {
    }
};

class ReverseLinkedList
{
public:
    //Time complexity : O(n)
    //Space complexity: O(1)
    //-----------------------------------
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }

        //Init pointers
        ListNode* previous_ptr = nullptr;
        ListNode* current_ptr = head;
        ListNode* next_ptr = head;

        while(current_ptr != nullptr)
        {
            //save next
            next_ptr = current_ptr->next;
            //reverse pointer
            current_ptr->next = previous_ptr;
            //move previous and current ptr
            previous_ptr = current_ptr;
            current_ptr = next_ptr;
        }

        head = previous_ptr;

        return head;
    }

    // Time complexity : O(n)
    // Space Complexity: O(n) - stack also uses memory
    //https://www.youtube.com/watch?v=O0By4Zq0OFc&ab_channel=BackToBackSWE - good tutorial
    //-----------------------------------
    ListNode* reverseListRecursive(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* rlh = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rlh;
    }

    void print(int i)
    {
        if(i > 5)
        {
            return;
        }

        //qWarning() << "Int is: " << i; //This prints 1,2,3,4,5, as it prints and then does a recursive call.

        print(i + 1);

        qWarning() << "Int is: " << i; //this prints 5,4,3,2,1 as it only prints after finishing the recursive call.
    }
};


namespace test
{
    void reverseLinkedListTests()
    {
        ReverseLinkedList linked_list;

        linked_list.print(0);

        ListNode* head = new ListNode();
        ListNode* one = new ListNode(1);
        ListNode* two = new ListNode(2);
        ListNode* three = new ListNode(3);
        ListNode* four = new ListNode(4);
        ListNode* five = new ListNode(5);

        head = one; //point head to the first element
        one->next = two;
        two->next = three;
        three->next = four;
        four->next = five;

        auto reversed_list = linked_list.reverseListRecursive(head);
        auto temp = reversed_list;
        while(temp != nullptr)
        {
            qWarning() << "Recursive reversed: " << temp->value;
            temp = temp->next;
        }
    }
}
