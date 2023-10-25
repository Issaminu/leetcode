struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *list1 = reverse(list1);
    ListNode *list2 = reverse(list2);
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;

    ListNode *answer = new ListNode();
    ListNode *res = answer;
    while (temp1 && temp2) {
      answer->val = temp1->val + temp2->val;
      if (temp1->next && temp2->next) {
        answer->next = new ListNode();
        answer = answer->next;
      }
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    while (temp1) {
      answer->val = temp1->val;
      if (temp1->next && temp2->next) {
        answer->next = new ListNode();
        answer = answer->next;
      }
      temp1 = temp1->next;
    }
    while (temp2) {
      answer->val = temp2->val;
      if (temp2->next) {
        answer->next = new ListNode();
        answer = answer->next;
      }
      temp2 = temp2->next;
    }

    return reverse(res);
  }
  ListNode *reverse(ListNode *head) {
    ListNode *ptr1 = nullptr;
    ListNode *ptr2 = head;
    while (ptr2) {
      ListNode *temp = ptr2->next;
      ptr2->next = ptr1;
      ptr1 = ptr2;
      ptr2 = temp;
    }
    return ptr1;
  }
};