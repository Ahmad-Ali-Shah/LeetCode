
/*

1)move the lowest value to start of lst one and 2

2)fnd the start and next one 

3) from lst two nset value untl and unless lst 2 ends 

4) f lst 2 ends assgn lst 1 end to the next one 





*/
class Solution {

    // 3 core functions

    void insetAtHead(ListNode*& head, int value)
    {
        ListNode* temp = new ListNode(value);

        temp->next = head;
        head = temp;
    }

    void inBetween(ListNode* strtNode, int v)
    {
        ListNode* temp = new ListNode(v);

        temp->next = strtNode->next;
        strtNode->next = temp;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = list1;

        // handle empty lists
        if(!list1) 
        return list2;
        if(!list2)
         return list1;

        // ensure list1 starts with the smaller value handle also the start one 
        if(list1->val > list2->val) {
            swap(list1, list2);
            head = list1;
        }

        while(list1 && list2) {

            int strt = list1->val;
            int next = INT_MAX;

            if(list1->next) {
                next = list1->next->val;
            }

            // insert list2 nodes between list1 nodes
            while(list2 && list2->val >= strt &&  list2->val <= next) {

                inBetween(list1, list2->val);

                list1 = list1->next;
                list2 = list2->next;
            }

            if(list1->next) {
                list1 = list1->next;
            }
            else {
                break;// end of lnk 
            }
        }

        // attach remaining nodes
        if(list2) {
            list1->next = list2;
        }

        return head;
    }
};
