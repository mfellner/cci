// Copyright 2013, Maximilian Fellner

#ifndef SORT_TEST_H_
#define SORT_TEST_H_

#include "gtest/gtest.h"
#include "sort.h"

using namespace mfellner;

////////////////////////////////////////
// Merge Sort Recursive
////////////////////////////////////////
// TEST(MergeSortTest, SortSmall) {
//   int a[4] = {7,4,8,2};
//   Sort::MergeSortRecursive(4, a);
//   Sort::ArrayPrint(4, a, "a");
// }

TEST(MergeSortRecursive, SortPositive) {
  int a[10] = {7,4,8,2,9,0,1,5,3,6};

  Sort::MergeSortRecursive(10, a);

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i, a[i]);
  }
}

TEST(MergeSortRecursive, SortNegative) {
  int a[10] = {-7,-4,-8,-2,-9,-0,-1,-5,-3,-6};

  Sort::MergeSortRecursive(10, a);

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i - 9, a[i]);
  }
}

TEST(MergeSortRecursive, SortMixed) {
  int a[10] = {-7,-4,8,-2,9,0,1,5,-3,6};

  Sort::MergeSortRecursive(10, a);

  for (int i = 0; i < 9; i++) {
    EXPECT_TRUE(a[i] < a[i + 1]);
  }
}

////////////////////////////////////////
// Merge Sort Iterative
////////////////////////////////////////
// TEST(MergeSortIterative, SortSmall) {
//   int a[3] = {3,2,1};//,2,1,0,-1};
//   Sort::MergeSortIterative(3, a);
//   Sort::ArrayPrint(3, a, "a");
// }

TEST(MergeSortIterative, SortPositive) {
  int a[10] = {7,4,8,2,9,0,1,5,3,6};

  Sort::MergeSortIterative(10, a);

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i, a[i]);
  }
}

TEST(MergeSortIterative, SortNegative) {
  int a[10] = {-7,-4,-8,-2,-9,-0,-1,-5,-3,-6};

  Sort::MergeSortIterative(10, a);

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i - 9, a[i]);
  }
}

TEST(MergeSortIterative, SortMixed) {
  int a[10] = {-7,-4,8,-2,9,0,1,5,-3,6};

  Sort::MergeSortIterative(10, a);

  for (int i = 0; i < 9; i++) {
    EXPECT_TRUE(a[i] < a[i + 1]);
  }
}

#endif  // SORT_TEST_H_
