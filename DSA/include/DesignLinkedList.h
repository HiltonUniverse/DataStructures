#pragma once

#include <QDebug>

class MyLinkedList
{
public:
    MyLinkedList()
    {
    }

    //-----------------------------------
    ~MyLinkedList()
    {
        while(size != 0)
        {
            deleteAtIndex(0); // we keep deleting head and shifting it to the next node until size == 0
        }

        head = nullptr;
        tail = head;

        qWarning()<<"------DESTRUCTOR CALLED----------";
        qWarning() << head << tail << "size: " << size;
        qWarning()<<"----------------" << '\n';
    }

    //-----------------------------------
    int get(int index)
    {
        if(auto iter = getNodeAtIndex(index))
        {
            return iter->val;
        }

        return -1;
    }

    //-----------------------------------
    void addAtHead(int val)
    {
        //this gives a stack behaviour: Last in first out.
        Node* new_node = new Node(val); //create a new node
        if(!tail)
        {
            tail = new_node; //put tail on the first inserted element.
        }
        new_node->next = head; //point its new node to head
        head = new_node; //make new node the head.
        ++size;
    }

    //-----------------------------------
    void addAtTail(int val)
    {
        Node* new_node = new Node(val);

        if(!tail) //means there was no ptr in the linked list, both head and tail will point to the first element
        {
            tail = new_node;
            head = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }

        ++size;
    }

    //-----------------------------------
    void addAtIndex(int index, int val)
    {
        if(index == 0)
        {
            addAtHead(val);
        }
        if(index == size)
        {
            addAtTail(val);
        }
        else
        {
            auto iter = getNodeAtIndex(index - 1);
            if(!iter)
            {
                return;
            }

            Node* new_node = new Node(val);
            new_node->next = iter->next;
            iter->next = new_node;
            ++size;
        }
    }

    //-----------------------------------
    void deleteAtIndex(int index)
    {
        if(!isValidIndex(index))
        {
            return;
        }

        if(index == 0)
        {
            Node* temp_head = head;
            head = head->next;
            delete temp_head;
            temp_head = nullptr;
        }
        else
        {
            if(auto iter = getNodeAtIndex(index - 1))
            {
                Node* to_delete = iter->next;
                iter->next = to_delete->next;
                if(index == (size -1))
                {
                    tail = iter;
                }

                delete to_delete;
                to_delete = nullptr;
            }
        }

        --size;
    }

    //-----------------------------------
    void print(MyLinkedList& list)
    {
        Node* dummy = head;
        while(dummy != nullptr)
        {
            qWarning() << "Print(): " << dummy->val;
            dummy = dummy->next;
        }

        qWarning() << "--------------";
        qWarning() << "size is: " << size;
        if(head && tail)
        {
            qWarning() << "HEAD IS:" << head->val << "TAIL IS: " << tail->val;
        }
        qWarning() << "--------------";
    }

    bool search(int i)
    {
        return search(head, i);
    }
private:
    //-----------------------------------
    struct Node
    {
        int val;
        Node* next;

        Node()
            : val(0)
            , next(nullptr)
        {
        }

        Node(int data)
            : val(data)
            , next(nullptr)
        {
        }

        Node(int data, Node* next)
            : val(data)
            , next(next)
        {
        }
    };

    //-----------------------------------
    //Recursive call
    int search(Node* head, int i)
    {
        if(!head)
        {
            return -1;
        }


        if(head->val == i)
        {
            return i;
        }

        return search(head->next, i);
    }

    //-----------------------------------
    bool isValidIndex(int index)
    {
        return index >= 0 && index <= (size - 1);
    }

    //-----------------------------------
    Node* getNodeAtIndex(int index)
    {
        if(!isValidIndex(index))
        {
            return nullptr;
        }

        if(index == 0)
        {
            return head;
        }
        else if(index == (size -1))
        {
            return tail;
        }

        Node* iter = head;
        int temp_index = 0;
        while(temp_index < index)
        {
            ++temp_index;
            iter = iter->next;
        }

        return iter;
    }

    int size = 0;
    Node* head = nullptr;
    Node* tail = head;
};


namespace test
{
    void myLinkedListTests()
    {
        /*
        {
            MyLinkedList linked_list;
            linked_list.addAtTail(1); //tail
            linked_list.addAtTail(2);
            linked_list.addAtTail(3); //head
            qWarning() << "Found valud: " << linked_list.search(3);
        }

        {
            MyLinkedList linked_list;
            linked_list.addAtHead(0);
            linked_list.addAtIndex(1,4);
            linked_list.addAtTail(8);
            linked_list.addAtTail(5);
            linked_list.addAtIndex(4,3);
            linked_list.addAtTail(0);
            linked_list.addAtTail(5);
            linked_list.addAtIndex(6,3);
            linked_list.deleteAtIndex(7);
            linked_list.deleteAtIndex(5);
            linked_list.addAtTail(4);
            qWarning() << linked_list.get(0);
        }

        {
                MyLinkedList linked_list;
                linked_list.addAtHead(1); //tail
                linked_list.addAtHead(2);
                linked_list.addAtHead(3); //head
                linked_list.print(linked_list); //expected : 3 2 1 - stack behaviour - last in first out.
            }

            {
                MyLinkedList linked_list;
                linked_list.addAtTail(4); //head
                linked_list.addAtTail(5);
                linked_list.addAtTail(6); //tail
                linked_list.print(linked_list); //expected: 4 5 6 - queue behaviour - first in last out.
            }

            {
                MyLinkedList linked_list;
                linked_list.addAtTail(4); //head
                linked_list.addAtTail(5);
                linked_list.addAtTail(6);
                linked_list.addAtTail(7);
                linked_list.addAtTail(8); //tail
                qWarning() << "Value at index 0: " <<linked_list.get(0); //expect 4
                qWarning() << "Value at index 1: " <<linked_list.get(1); //expect 5
                qWarning() << "Value at index 2: " <<linked_list.get(2); //expect 6
                qWarning() << "Value at index 3: " <<linked_list.get(3); //expect 7
                qWarning() << "Value at index 4: " <<linked_list.get(4); //expect 8
                qWarning() << "Value at index 5: " <<linked_list.get(5); //expect -1
                qWarning() << "Value at index -1: " <<linked_list.get(-1); //expect -1
            }

            {
                MyLinkedList linked_list;
                linked_list.addAtIndex(0, 0);
                linked_list.addAtIndex(1, 1);
                linked_list.addAtIndex(2, 2);
                linked_list.addAtIndex(3, 4);
                linked_list.addAtIndex(4, 5);
                linked_list.addAtIndex(3, 3);
                linked_list.print(linked_list);
            }

        {
            MyLinkedList linked_list;

            linked_list.addAtTail(0);
            linked_list.addAtTail(1);
            linked_list.addAtTail(2);
            linked_list.addAtTail(3);
            linked_list.addAtTail(4);
            linked_list.print(linked_list);

            linked_list.deleteAtIndex(2);
            linked_list.print(linked_list);
        }*/
    }
}
