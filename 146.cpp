#include <unordered_map>
struct ListNode {
  int key;
  int val;
  ListNode *next;
  ListNode() : key(0), val(0), next(nullptr) {}
  ListNode(int x) : key(x), val(x), next(nullptr) {}
  ListNode(int x, int y) : key(x), val(y), next(nullptr) {}
  ListNode(int x, int y, ListNode *next) : key(x), val(y), next(next) {}
};

void remove(ListNode *ListNode) {
  ListNode *prev = ListNode->prev;
  ListNode *next = ListNode->next;

  prev->next = next;
  next->prev = prev;
}

// insert ListNode at right
void insert(ListNode *ListNode) {
  ListNode *prev = right->prev;
  ListNode *next = right;

  prev->next = ListNode;
  next->prev = ListNode;

  ListNode->prev = prev;
  ListNode->next = next;
}

class LRUCache {
  std::unordered_map<int, ListNode *> cache;
  int capacity;

public:
  LRUCache(int capacity) {
    ListNode *head = new ListNode(0, 0);
    this->capacity = capacity;
    cache.insert({1, head});
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      int val = cache[key]->val;
      cache.return val;
    }
    return -1;
  }

  void put(int key, int value) {}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */