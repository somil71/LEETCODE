
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Step 1: Find length and last node
        ListNode* temp = head;
        int len = 1;

        while (temp->next != nullptr) {
            temp = temp->next;
            len++;
        }

        // Step 2: Reduce unnecessary rotations
        k = k % len;

        if (k == 0)
            return head;

        // Step 3: Make the list circular
        temp->next = head;

        // Step 4: Find the new tail
        int steps = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 5: Update head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
