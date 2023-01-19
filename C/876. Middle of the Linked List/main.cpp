#include <cstdio>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head)
{
    int count = 0;

    for(ListNode* i = head; i != nullptr; i = i->next)
    {
        ++count;
    }

    int middle = count / 2 + 1;
    ListNode* result = head;

    for(int i = 1; i < middle; i += 1)
    {
        result = result->next;
    }

    return result;
}

int main(int argc, char** argv)
{

    return 0;
}
