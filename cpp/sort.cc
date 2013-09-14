// Copyright 2013, Maximilian Fellner

#include "sort.h"
#include <string.h>
#include <iostream>
#include <algorithm>

namespace mfellner {

// worst case O(n log n), best case O(n)
void Sort::MergeSortRecursive(int n, int a[n]) {
  MSortSplit(0, n - 1, a);
}

void Sort::MSortSplit(int i, int j, int a[]) {
  if (i < j) {
    int k = (i + j) / 2;
    MSortSplit(    i, k, a);
    MSortSplit(1 + k, j, a);
    MSortMerge( i, k, j, a);
  }
}

void Sort::MergeSortIterative(int n, int a[n]) {
  for (int w = 1; w < n; w = w * 2) {
    for (int i = 0; i < n; i = i + w * 2) {
      MSortMerge(i, i + w - 1, std::min(i + w * 2, n) - 1, a);
    }
  }
}

void Sort::MSortMerge(int i, int k, int j, int a[]) {
  int n = j - i + 1;
  int b[n];

  // std::cout << "i:" << i << " k:" << k << " j:" << j << " --------" << std::endl;
  for (int m = 0, l = i, r = k + 1; m < n; m++) {
    if (r > j || (l <= k && a[l] < a[r])) {
      b[m] = a[l];
      l++;
    } else {
      b[m] = a[r];
      r++;
    }
  }

  memcpy(&a[i], b, sizeof(b));
}

void Sort::ArrayPrint(int n, int a[n], const char* s) {
  std::cout << s <<":[";
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ",";
  }
  std::cout << "]" << std::endl;
}

}
