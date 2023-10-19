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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return nullptr;
    }
    if (head->next->next == nullptr)
    {
      if (n == 1)
      {
        return new ListNode(head->val, nullptr);
      }
      else
      {
        return new ListNode(head->next->val, nullptr);
      }
    }
    ListNode *reverseHead = reverse(head);
    ListNode *temp = reverseHead;
    if (n == 1)
    {
      reverseHead = reverseHead->next;
    }
    else
    {

      while (n > 2)
      {
        temp = temp->next;
        n--;
      }
      temp->next = temp->next->next;
    }
    return reverse(reverseHead);
  }

  ListNode *reverse(ListNode *head)
  {
    ListNode *ptr1 = nullptr;
    ListNode *ptr2 = head;
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