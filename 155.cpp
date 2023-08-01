#include <stack>
#include <iostream>
using namespace std;
class Node
{

public:
  int value;
  Node *next;
  Node()
  {
    value = 0;
    next = nullptr;
  }
  Node(int number)
  {
    value = number;
    next = nullptr;
  }
};

class MinStack
{
  stack<int> lastMin;

public:
  Node *head;
  MinStack()
  {
    head = NULL;
  }

  void push(int val)
  {
    if (lastMin.empty())
    {
      lastMin.push(val);
    }
    else if (val <= lastMin.top())
    {
      lastMin.push(val);
    }
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }

  void pop()
  {
    Node *temp = head;
    head = head->next;
    if (temp->value == lastMin.top())
    {
      lastMin.pop();
    }
    delete temp;
  }

  int top()
  {
    return head->value;
  }

  int getMin()
  {
    return lastMin.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */