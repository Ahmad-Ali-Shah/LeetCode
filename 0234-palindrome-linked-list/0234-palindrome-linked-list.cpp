/*

class Solution {

    ListNode* getLast(int counter, ListNode* head) {
        int count = 0;

        while (count < counter && head) {
            head = head->next;
            count++;
        }

        return head;
    }

public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) {
            return true;
        }

        ListNode* start = head;
        ListNode* end = head;

        int counter = 0;

        while (end->next != nullptr) {
            end = end->next;
            counter++;
        }

        /////////////////////////

        /// yarrr arry ma travese kiiun ni kr sakta

        /////////////////////////

        int index = 0;

        while (index <= counter / 2) {

            if (start->val != end->val) {
                return false;
            }

            end = getLast(counter - index - 1, head);

            start = start->next;
            index++;
        }

        return true;
    }
};

high complexity o(n^2)
*/


class Solution {

public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) {
            return true;
        }


        ListNode* slow = head;
        ListNode* fast = head;

      
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* preserver = curr->next;
            curr->next = prev;
            prev = curr;
            curr = preserver;
        }

        // Compare first half and reversed second half
        ListNode* start = head;
        ListNode* end = prev;

        while (end) {

            if (start->val != end->val) {
                return false;
            }

            start = start->next;
            end = end->next;
        }

        return true;
    }
};