#include <unordered_map>

using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    unordered_map<Node *, Node *> map;
    Node *h = head;
    while (h) {
      map[h] = new Node(h->val);
      h = h->next;
    }
    h = head;
    while (h) {
      Node *newNode = map[h];
      newNode->next = map[h->next];
      newNode->random = map[h->random];
      h = h->next;
    }

    return map[head];
  }
};