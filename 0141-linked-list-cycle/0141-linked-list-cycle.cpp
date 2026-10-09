class Solution {
public:
    bool hasCycle(ListNode *head) {

        // using fast and slow pointer to check whether a cycle exists

        if (!head || !head->next)
            return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
};