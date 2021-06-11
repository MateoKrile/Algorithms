//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == nullptr || head->next==nullptr) { return nullptr; }
        ListNode* hare = head;
        ListNode* tortoise = head;
        while(true)
        {
            hare = hare->next;
            tortoise = tortoise->next;
            if(hare == nullptr || hare->next==nullptr) { return nullptr; }
            else
            {
                hare = hare->next;
            }
            if(hare == tortoise) { break; }
        }
        while(head != hare)
        {
            head = head->next;
            hare = hare->next;
        }
        return hare;
    }
};