#pragma once
#include <QDebug>

class ReorderList
{
public:
    //-----------------------------------
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    //-----------------------------------
    //T : O(n) * O(n) = O(n^2)
    //S : O(1)
    void reorderListBruteForceLinear(ListNode* head)
    {
        ListNode* temp = head;
        while(temp->next && temp->next->next) //O(n) + O(n - 2) + O(n-4) ....
        {
            ListNode* second_last = temp;
            while(second_last->next->next) //O(n - 1) = O(n)
            {
                second_last = second_last->next;
            }

            second_last->next->next = temp->next;
            temp->next = second_last->next;
            second_last->next = nullptr;
            temp = temp->next->next;
        }
    }

    //-----------------------------------
    //T : O(n) * O(n) = O(n^2)
    //S : O(n) = stack space used!
    void reorderListBruteForceRecursive(ListNode* head)
    {
        if(!head || !head->next || !head->next->next)
        {
            return;
        }

        ListNode* second_last = head;
        while(second_last->next->next)
        {
            second_last = second_last->next;
        }

        second_last->next->next = head->next;
        head->next = second_last->next;
        second_last->next = nullptr;

        reorderListBruteForceRecursive(head->next->next);
    }

    //-----------------------------------
    //T : O(n)
    //S : O(1)
    void reorderList(ListNode* head)
    {
        //3 steps
        //1. find the middle node
        //2. reverse the nodes after middle node
        //3. reorder
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow;
        ListNode* prev = nullptr;
        ListNode* next = slow;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l2->next)
        {
            next = l1->next;
            l1->next = l2;
            l1 = next;

            next = l2->next;
            l2->next = l1;
            l2 = next;
        }
    }
};

namespace test
{
    void ReorderListTests()
    {
        using Node = ReorderList::ListNode;
        //ITERATIVE
        {
            Node* head = nullptr;
            Node* first = new Node(1);
            Node* second = new Node(2);
            Node* third = new Node(3);
            Node* fourth = new Node(4);

            head = first;
            first->next = second;
            second->next = third;
            third->next = fourth;

            ReorderList reorder;


            reorder.reorderListBruteForceLinear(head);

            auto curr = head;
            while(curr)
            {
                qWarning() << curr->val;
                curr = curr->next;
            }

            delete first;
            delete second;
            delete third;
            delete fourth;
        }

        qWarning() << "Recursive";
        //RECURSIVE
        {
            Node* head = nullptr;
            Node* first = new Node(1);
            Node* second = new Node(2);
            Node* third = new Node(3);
            Node* fourth = new Node(4);

            head = first;
            first->next = second;
            second->next = third;
            third->next = fourth;

            ReorderList reorder;


            reorder.reorderListBruteForceRecursive(head);

            auto curr = head;
            while(curr)
            {
                qWarning() << curr->val;
                curr = curr->next;
            }

            delete first;
            delete second;
            delete third;
            delete fourth;
        }

        qWarning() << "Two pointer linear";
        //RECURSIVE
        {
            Node* head = nullptr;
            Node* first = new Node(1);
            Node* second = new Node(2);
            Node* third = new Node(3);
            Node* fourth = new Node(4);
            Node* fifth = new Node(5);

            head = first;
            first->next = second;
            second->next = third;
            third->next = fourth;
            fourth->next = fifth;

            ReorderList reorder;


            reorder.reorderList(head);

            auto curr = head;
            while(curr)
            {
                qWarning() << curr->val;
                curr = curr->next;
            }

            delete first;
            delete second;
            delete third;
            delete fourth;
            delete fifth;
        }
    }
}
