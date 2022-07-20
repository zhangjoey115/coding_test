#include <algorithm>
#include <iostream>
using namespace std;

void max_heapify(vector<int>& arr, int start, int end) {
  // 建立父節點指標和子節點指標
  int dad = start;
  int son = dad * 2 + 1;
  while (son <= end) {  // 若子節點指標在範圍內才做比較
    if (son + 1 <= end &&
        arr[son] < arr[son + 1])  // 先比較兩個子節點大小，選擇最大的
      son++;
    if (arr[dad] > arr[son])  // 如果父節點大於子節點代表調整完畢，直接跳出函數
      return;
    else {  // 否則交換父子內容再繼續子節點和孫節點比較
      swap(arr[dad], arr[son]);
      dad = son;
      son = dad * 2 + 1;
    }
  }
}

void heap_sort(vector<int>& arr, int len) {
  // 初始化，i從最後一個父節點開始調整
  for (int i = len / 2 - 1; i >= 0; i--) max_heapify(arr, i, len - 1);
  // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
  for (int i = len - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    max_heapify(arr, 0, i - 1);
  }
}

int main() {
  vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int len = arr.size();
  heap_sort(arr, len);
  for (int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << endl;
  return 0;
}