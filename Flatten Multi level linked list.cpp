// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) 
    {
        if(!head) { return nullptr; }
        Node* current = head;
        while(current)
        {
            if(current->child)
            {
                Node* tail = current->child;
                while (tail->next)
                {
                    tail = tail->next;
                }
                tail->next = current->next;
                if(tail->next)
                {
                    tail->next->prev = tail;
                }
                current->next = current->child;
                current->next->prev = current;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};