// Copyright 2013, Maximilian Fellner

#include "sort.h"
#include <string.h>
#include <iostream>

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

void Sort::MSortMerge(int i, int k, int j, int a[]) {
  int pn = k - i + 1;
  int qn = j - k;
  int p[pn], q[qn];

  memcpy(p, &a[i    ], sizeof(p));
  memcpy(q, &a[k + 1], sizeof(q));

  for (int m = i, l = 0, r = 0; m <= j; m++) {
    if (qn == 0 || (pn > 0 && p[l] < q[r])) {
      a[m] = p[l];
      pn--;
      l++;
    } else {
      a[m] = q[r];
      qn--;
      r++;
    }
  }
}

void Sort::ArrayPrint(int n, int a[n], const char* s) {
  std::cout << s <<":[";
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ",";
  }
  std::cout << "]" << std::endl;
}

}
