class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = nullptr;
        ListNode* current = nullptr; // always whenever you need to indsert make the two pointer start and move 

        int carry = 0;

        while (l1 || l2) {

            int sum = 0;

            if (l1 && l2)
                sum = l1->val + l2->val + carry;

            else if (l1)
                sum = l1->val + carry;

            else
                sum = l2->val + carry;

            carry = sum / 10;
            sum = sum % 10;

            // make a node and then push it
            ListNode* temp = new ListNode(sum);

            if (!result) {
                result = temp;
                current = temp;
            }

            else {
                // make temp and add to next
                current->next = temp;
                current = current->next;
            }

            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        // if carry is left
        if (carry) {
            current->next = new ListNode(); 

            current->next->val = carry;

            current->next->next = nullptr;
        }

        return result;
    }
};