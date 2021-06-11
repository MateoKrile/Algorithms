#include <algorithm>;
#include <Linked List.cpp>;

using namespace std;

class App
{
public:

    Node* ReverseLinkedList()
    {
        Node* head = CreateLinkedList(7);
        Node* prev = nullptr;
        Node* current = head;
        while(current)
        {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    Node* ReverseMNLinkedList(int m, int n)
    {
        Node* head = CreateLinkedList(7);
        Node* prev = nullptr;
        Node* current = head;
        Node* start = new Node;
        Node* tail = new Node;
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
            Node* next = current->next;
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