

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* returnList = new ListNode;
        ListNode* returnListed = returnList;

        bool carry = 0;

        while (l1 || l2) {

            if (l2 && l1) {

                returnList->val = ((l1->val + l2->val) % 10 + carry)%10;

                carry = (l1->val + l2->val + carry) / 10;

                l1 = l1->next;
                l2 = l2->next;
                if (l1 || l2) {

                    returnList->next = new ListNode;

                    returnList = returnList->next;
                }

            } else {
                if (l1) {

                    returnList->val = (l1->val + carry) % 10;

                    carry = (l1->val + carry) / 10;

                    l1 = l1->next;

                    if (l1) {

                        returnList->next = new ListNode;

                        returnList = returnList->next;
                    }

                } else if (l2) {

                    returnList->val = (l2->val + carry) % 10;

                    carry = (l2->val + carry) / 10;

                    l2 = l2->next;

                    if (l2) {
                        returnList->next = new ListNode;

                        returnList = returnList->next;
                    }
                }
            }
        }

        if (carry) {
            returnList->next = new ListNode;
            returnList = returnList->next;

            returnList->val = carry;

            returnList->next = nullptr;
        }

        return returnListed;
    }
};