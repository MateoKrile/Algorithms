#include <algorithm>;


class LinkedList
{
public:
    struct Node
    {
    public:
        Node* next = nullptr;

        int value;
    };

    static Node* CreateLinkedList(int numOfNodes)
    {
        Node* head = new Node;
        head->next = nullptr;
        head->value = 1;
        Node* current = head;
        for (int i = 2; i < numOfNodes; i++)
        {
            Node* next = new Node;
            next->next = nullptr;
            next->value = i;
            current->next = next;
            current = next;
        }
        return head;
    }
};


using namespace std;

class App
{
public:

    LinkedList::Node* ReverseLinkedList()
    {
        LinkedList::Node* head = LinkedList::CreateLinkedList(7);
        LinkedList::Node* prev = nullptr;
        LinkedList::Node* current = head;
        while(current)
        {
            LinkedList::Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    LinkedList::Node* ReverseMNLinkedList(int m, int n)
    {
        LinkedList::Node* head = LinkedList::CreateLinkedList(7);
        LinkedList::Node* prev = nullptr;
        LinkedList::Node* current = head;
        LinkedList::Node* start = new LinkedList::Node;
        LinkedList::Node* tail = new LinkedList::Node;
        int nodeIndex = 1;
        while(nodeIndex < m)
        {
            start = current;
            current = current->next;
            nodeIndex ++;
        }
        tail = current;
        while(nodeIndex >= m && nodeIndex <= n)
        {
            LinkedList::Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            nodeIndex ++;
        }
        if(m > 1)
        {
            return head;
        }
        else
        {
            return prev;
        }
    }
};