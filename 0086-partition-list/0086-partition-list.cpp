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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeDummy(0);
        ListNode afterDummy(0);
        
        ListNode* beforeCurr = &beforeDummy;
        ListNode* afterCurr = &afterDummy;
        
        while (head != nullptr) {
            if (head->val < x) {
                beforeCurr->next = head;
                beforeCurr = beforeCurr->next;
            } else {
                afterCurr->next = head;
                afterCurr = afterCurr->next;
            }
            head = head->next;
        }
        
        afterCurr->next = nullptr;
        
        beforeCurr->next = afterDummy.next;
        
        return beforeDummy.next;
    }
};