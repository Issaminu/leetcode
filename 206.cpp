#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *temp1 = head;
    ListNode *temp2 = head;
    while (temp1 != nullptr)
    {
      ListNode *next = temp1->next;
      temp1->next = temp2;
      temp2 = temp1;
      temp1 = next;
    }
    return temp1;
  }
};