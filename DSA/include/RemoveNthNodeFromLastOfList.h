#pragma once
#include <QDebug>

class RemoveNthNodeFromLastOfList
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(!head || !head->next)
        {
            return {};
        }

        ListNode* left = head;
        ListNode* right = head;

        while(n > 0)
        {
            right = right->next;
            n--;
        }

        if(!right)
        {
            return head->next;
        }

        while(right->next)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return head;
    }
};

namespace test
{
    //-----------------------------------
    void RemoveNthNodeFromLastOfListTests()
    {
        RemoveNthNodeFromLastOfList remove;

        using Node = RemoveNthNodeFromLastOfList::ListNode;
        {
            Node* head = new Node();
            Node* first = new Node(1);
            Node* second = new Node(2);
            Node* third = new Node(3);
            Node* fourth = new Node(4);
            Node* fifth = new Node(5);

            head->next = first;
            first->next = second;
            second->next = third;
            third->next = fourth;
            fourth->next = fifth;

            auto final = remove.removeNthFromEnd(head->next, 2);
            qWarning() << "2nd element removed: ";
            while(final)
            {
                qWarning() << final->val;
                final = final->next;
            }
        }

        {
            Node* head = new Node();
            Node* first = new Node(1);
            Node* second = new Node(2);

            head->next = first;
            first->next = second;

            auto final = remove.removeNthFromEnd(head->next, 1);
            qWarning() << "1nd element removed: ";
            while(final)
            {
                qWarning() << final->val;
                final = final->next;
            }
        }

        {
            Node* head = new Node();
            Node* first = new Node(1);

            head->next = first;

            auto final = remove.removeNthFromEnd(head->next, 1);
            qWarning() << "1nd element removed: ";
            while(final)
            {
                qWarning() << final->val;
                final = final->next;
            }
        }
    }
}
