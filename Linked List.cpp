struct Node
{
    public:
        Node* next = nullptr;

        int value;
};
 
Node* CreateLinkedList(int numOfNodes)
{
    Node* head = new Node;
    head->next = nullptr;
    head->value = 1;
    Node* current = head;
    for(int i=2; i<numOfNodes; i++)
    {
        Node* next = new Node;
        next->next = nullptr;
        next->value = i;
        current->next = next;
        current = next;
    }
    return head;
