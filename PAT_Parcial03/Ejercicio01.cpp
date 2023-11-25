#include "Ejercicio01.h"
#include<vector>

Node<int>* Ejercicio01::sortList(Node<int>* head)
{
    if (!head || !head->next)
        return head;

    Node<int>* slow = head;
    Node<int>* fast = head;
    Node<int>* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) prev->next = nullptr;

    Node<int>* left = sortList(head);
    Node<int>* right = sortList(slow);

    Node<int>** it = &head;

    while (left && right) {
        if (left->value > right->value) {
            *it = left;
            left = left->next;
        }
        else {
            *it = right;
            right = right->next;
        }
        it = &((*it)->next);
    }

    if (left)
        *it = left;

    if (right)
        *it = right;

    return head;
}

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    Node<int>* headf = new Node<int>();
    Node<int>* tmp3 = headf;
    Node<int>* tmp = nullptr;
    Node<Node<int>*>* tmp2 = lists;
    while (tmp2)
    {
        tmp = tmp2->value;
        while (tmp)
        {
            Node<int>* newNode = new Node<int>();
            if (headf == nullptr)
            {
                newNode->next = nullptr;
                headf = newNode;
                tmp = tmp->next;
                tmp3 = headf;
                continue;
            }
            tmp3->next = newNode;
            tmp3 = tmp3->next;
            tmp = tmp->next;
        }
        tmp2 = tmp2->next;
    }
    return sortList(headf);
}
