#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head)
{
    for(ListNode* i = head; i != nullptr; i = i->next)
    {
        printf("%d ", i->val);
    }
    printf("\n");
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int count = 0;

    for(ListNode* i = head; i != nullptr; i = i->next)
    {
        ++count;
    }

    if (count == 1)
    {
        return nullptr;
    }

    ListNode* previous = head;

    for(int i = 0; i < count - n - 1; i += 1)
    {
        previous = previous->next;
    }

    if (previous == head && count - n - 1 < 0)
        return head->next;

    previous->next = previous->next->next;

    return head;
}

int main(int argc, char** argv)
{
//    ListNode* fifth = new ListNode(5);
//    ListNode* fourth = new ListNode(4, fifth);
//    ListNode* third = new ListNode(3, fourth);
    ListNode* second = new ListNode(2, nullptr);
    ListNode* first = new ListNode(1, second);

    printList(first);

    printList(removeNthFromEnd(first, 2));

    return 0;
}
