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
  void reorderList(ListNode *head)
  {
    if (!head || !head->next)
      return; // Handle empty list or single element list

    // Find the middle of the list
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode *secondHalf = slow->next;
    slow->next = nullptr;
    secondHalf = reverse(secondHalf);

    // Interleave the two halves
    ListNode *first = head;
    ListNode *second = secondHalf;
    while (second)
    {
      ListNode *temp1 = first->next;
      ListNode *temp2 = second->next;
      first->next = second;
      second->next = temp1;
      first = temp1;
      second = temp2;
    }
  }
  ListNode *reverse(ListNode *node)
  {
    ListNode *ptr1 = nullptr;
    ListNode *ptr2 = node;
    while (ptr2)
    {
      ListNode *temp = ptr2->next;
      ptr2->next = ptr1;
      ptr1 = ptr2;
      ptr2 = temp;
    }
    return ptr1;
  }
};