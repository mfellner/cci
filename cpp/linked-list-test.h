// Copyright 2013, Maximilian Fellner

#ifndef LINKED_LIST_TEST_H_
#define LINKED_LIST_TEST_H_

#include "linked-list.h"
#include "gtest/gtest.h"
#include <string>

using namespace mfellner;

TEST(LinkedListTest, Add) {
  LinkedList<int> list;

  EXPECT_EQ(0, list.Size());

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(3, list.Size());
}

TEST(LinkedListTest, GetFirst) {
  LinkedList<int> list;

  EXPECT_EQ(0, list.GetFirst());

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  int k = *list.GetFirst();
  EXPECT_EQ(1, k);
}

TEST(LinkedListTest, GetLast) {
  LinkedList<int> list;

  EXPECT_EQ(0, list.GetLast());

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  int k = *list.GetLast();
  EXPECT_EQ(3, k);
}

TEST(LinkedListTest, Clear) {
  LinkedList<int> list;

  int a = 1, b = 2;
  list.Add(&a);
  list.Add(&b);

  EXPECT_EQ(2, list.Size());

  list.Clear();

  EXPECT_EQ(0, list.Size());
  EXPECT_EQ(0, list.GetFirst());
  EXPECT_EQ(0, list.GetLast());
}

TEST(LinkedListTest, ClearDoesNotDeleteData) {
  LinkedList<std::string> list;

  std::string stack_string = "Hello, World!";
  list.Add(&stack_string);
  list.Clear();

  EXPECT_EQ(0, list.Size());
  EXPECT_EQ("Hello, World!", stack_string);

  std::string* heap_string = new std::string("Good day to you!");
  list.Add(heap_string);
  list.Clear();

  EXPECT_EQ(0, list.Size());
  EXPECT_EQ("Good day to you!", *heap_string);

  delete heap_string;
  heap_string = 0;
}

#endif  // LINKED_LIST_TEST_H_
