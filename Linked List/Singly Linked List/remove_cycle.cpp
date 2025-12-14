
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool iscycle = false;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                iscycle = true;
                break;
            }
        }
        slow = head;
        ListNode *prev = nullptr;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = nullptr;
        return slow;
    }
};