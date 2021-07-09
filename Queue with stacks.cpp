#include <stack>;

using namespace std;

class MyQueue {
public:
    stack<int> firstStack;
    stack<int> queue;
    /** Initialize your data structure here. */
    MyQueue() 
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {   
        while(!queue.empty())
        {
            firstStack.push(queue.top());
            queue.pop();
        }
        queue.push(x);
        while(!firstStack.empty())
        {
            queue.push(firstStack.top());
            firstStack.pop();
        }    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int r = queue.top();
        queue.pop();
        return r;
    }
    
    /** Get the front element. */
    int peek() 
    {
        return queue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return queue.empty();
    }
};