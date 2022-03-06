
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// ERROR! Consider super long num list! More than long/double

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // vector<int> num1, num2;
    int i = 0;
    double num1 = 0;
    double num2 = 0;
    double sum = 0;
    ListNode* tmp_list = l1;
    while (tmp_list != nullptr) {
      // num1.push_back(tmp_list->val);
      auto cur_n = pow(10, i);
      num1 += tmp_list->val * (int)(cur_n);
      tmp_list = tmp_list->next;
      i++;
    }

    i = 0;
    tmp_list = l2;
    while (tmp_list != nullptr) {
      // num1.push_back(tmp_list->val);
      auto cur_n = pow(10, i);
      num2 += tmp_list->val * (int)(cur_n);
      tmp_list = tmp_list->next;
      i++;
    }

    sum = num1 + num2;
    if ((int)sum == 0) {
      ListNode* output = new ListNode(0);
      return output;
    }

    int num_t = 0;
    int num_remain = sum;
    ListNode* output = nullptr;
    ListNode* cur_output = nullptr;
    while (num_remain > 0) {
      num_t = (num_remain % 10);
      num_remain = num_remain / 10;
      if (cur_output == nullptr) {
        output = new ListNode(num_t);
        cur_output = output;
      } else {
        cur_output->next = new ListNode(num_t);
        cur_output = cur_output->next;
      }
    }
    return output;
  }
};

int main() {
  ListNode a0(5), a1(6), a2(7);
  ListNode b0(9), b1(8), b2(7), b3(6);
  a0.next = &a1;
  a1.next = &a2;
  b0.next = &b1;
  b1.next = &b2;
  b2.next = &b3;

  Solution s;
  auto res = s.addTwoNumbers(&a0, &b0);
  cout << res->val << ", " << res->next->val << ", " << res->next->next->val
       << ", " << res->next->next->next->val << endl;

  return 0;
}
