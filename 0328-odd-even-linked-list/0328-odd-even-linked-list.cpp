/*


For odd or even idexes 
class Solution {
public:

    ListNode* oddEvenList(ListNode* head) {

        // we need to do it divison by cases

        ListNode* even = nullptr;
        ListNode* odd = nullptr;

        ListNode* evenStart = nullptr;
        ListNode* oddStart = nullptr;

        ListNode* current = head;

        while (current) {

            
           

            // for even

            if (current->val % 2 == 0) {

                if (!even) {
                    even = current;
                    evenStart = current;
                }

                else {
                    even->next = current; // move to next
                    even = current; // place the next
                }

            }

            else {

                if (!odd) {
                    odd = current;
                    oddStart = current;
                }

                else {
                    odd->next = current;
                    odd = current;
                }
            }

            // move the pointer
            current = current->next;
        }

        if (odd) {
            odd->next = evenStart; // you need to place
        }

        if (even) {
            even->next = nullptr;
        }

        return oddStart ? oddStart : evenStart;
    }
};
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {



        if (!head || !head->next) {
            return head; // for one head 
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = even;

        while (even && even->next) {

            odd->next = even->next;

            odd = odd->next;// ie even 


            even->next = odd->next;

            even = even->next;


        }

        odd->next = evenStart;

        return head;
    }
};