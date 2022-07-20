
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct NodeList {
  int key;
  NodeList* next;
  NodeList* before;
  NodeList(int k) : key(k), next(nullptr), before(nullptr) {}
};

class LRUCache {
 public:
  unordered_map<int, int> lru_;
  NodeList* node_old_;
  int capacity_;

 public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    node_old_ = nullptr;
  }

  int get(int key) {
    if (lru_.count(key) < 1)
      return -1;
    else {
      auto node = node_old_;
      while (1) {
        if (node->key == key) {
          if (node == node_old_) {
            node_old_ = node_old_->next;
            break;
          } else if (node == node_old_->before) {
            break;
          } else {
            node->before->next = node->next;
            node->next->before = node->before;
            node->next = node_old_;
            node->before = node_old_->before;
            node_old_->before->next = node;
            node_old_->before = node;
            break;
          }
        } else {
          node = node->next;
        }
      }
      return lru_[key];
    }
  }

  void put(int key, int value) {
    if (lru_.size() < capacity_) {
      if (lru_.count(key) < 1) {  // new
        auto node = new NodeList(key);
        if (node_old_ != nullptr) {
          node_old_->before->next = node;
          node->before = node_old_->before;
          node->next = node_old_;
          node_old_->before = node;
        } else {
          node_old_ = node;
          node_old_->before = node;
          node_old_->next = node;
        }
      }
      lru_[key] = value;
    } else {
      if (lru_.count(key) < 1) {  // new key
        if (capacity_ == 1) {
          node_old_->key = key;
        } else {
          auto node = new NodeList(key);
          auto node_tmp = node_old_;
          node_old_ = node_tmp->next;
          node_old_->before = node;
          node_tmp->before->next = node;
          node->next = node_old_;
          node->before = node_tmp->before;
          delete node_tmp;
        }
      }
      lru_.erase(node_old_->key);
      lru_[key] = value;
    }
  }
};

int main() {
  // LRUCache* obj = new LRUCache(3);
  // int param_1 = obj->get(11);
  // obj->put(12, 15);
  // obj->put(11, 14);
  // obj->put(10, 13);
  // obj->get(11);
  // obj->put(9, 12);

  // LRUCache* lRUCache = new LRUCache(2);
  // lRUCache->put(1, 1);  // 缓存是 {1=1}
  // lRUCache->put(2, 2);  // 缓存是 {1=1, 2=2}
  // lRUCache->get(1);     // 返回 1
  // lRUCache->put(3, 3);  // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  // lRUCache->get(2);  // 返回 -1 (未找到)
  // lRUCache->put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  // lRUCache->get(1);  // 返回 -1 (未找到)
  // lRUCache->get(3);  // 返回 3
  // lRUCache->get(4);  // 返回 4

  // LRUCache* lRUCache = new LRUCache(1);
  // lRUCache->put(2, 1);
  // lRUCache->get(2);
  // lRUCache->put(3, 2);
  // lRUCache->get(2);
  // lRUCache->get(3);
  // ["LRUCache","put","get","put","get","get"]
  // [[1],[2,1],[2],[3,2],[2],[3]]

  LRUCache* lRUCache = new LRUCache(2);
  lRUCache->get(2);
  lRUCache->put(2, 6);
  lRUCache->get(1);
  lRUCache->put(1, 5);
  lRUCache->put(1, 2);
  lRUCache->get(1);
  lRUCache->get(2);
  // ["LRUCache","get","put","get","put","put","get","get"]
  // [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
  return 0;
}