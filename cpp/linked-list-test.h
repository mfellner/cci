// Copyright 2014, Maximilian Fellner

#ifndef LINKED_LIST_TEST_H_
#define LINKED_LIST_TEST_H_

#include "linked-list.h"
#include "gtest/gtest.h"
#include <exception>
#include <string>

using namespace mfellner;

TEST(LinkedListTest, New) {
  LinkedList<int> list;
  EXPECT_EQ(0, list.Size());
}

////////////////////////////////////////
// Add
////////////////////////////////////////
TEST(LinkedListTest, Add) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(3, list.Size());
  EXPECT_EQ(1, *list.Get(0));
  EXPECT_EQ(2, *list.Get(1));
  EXPECT_EQ(3, *list.Get(2));
}

////////////////////////////////////////
// Add Index
////////////////////////////////////////
TEST(LinkedListTest, AddIndexFront) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;

  list.Add(0, &a);
  list.Add(0, &b);
  list.Add(0, &c);

  EXPECT_EQ(3, list.Size());
  EXPECT_EQ(3, *list.Get(0));
  EXPECT_EQ(2, *list.Get(1));
  EXPECT_EQ(1, *list.Get(2));
}

TEST(LinkedListTest, AddIndexBack) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;

  list.Add(0, &a);
  list.Add(1, &b);
  list.Add(2, &c);

  EXPECT_EQ(3, list.Size());
  EXPECT_EQ(1, *list.Get(0));
  EXPECT_EQ(2, *list.Get(1));
  EXPECT_EQ(3, *list.Get(2));
}

TEST(LinkedListTest, AddIndexMiddle) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;

  list.Add(0, &a);
  list.Add(1, &b);
  list.Add(1, &c);

  EXPECT_EQ(3, list.Size());
  EXPECT_EQ(1, *list.Get(0));
  EXPECT_EQ(3, *list.Get(1));
  EXPECT_EQ(2, *list.Get(2));
}

TEST(LinkedListTest, AddIndexShouldThrow) {
  LinkedList<int> list;

  int a = 1, b = 2;
  bool failed = false;

  try {
    list.Add(1, &a);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
  failed = false;

  list.Add(0, &a);

  try {
    list.Add(-1, &b);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
  failed = false;

  try {
    list.Add(2, &b);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
}

////////////////////////////////////////
// Add First
////////////////////////////////////////
TEST(LinkedListTest, AddFirst) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3, d = 4;
  list.AddFirst(&a);
  list.AddFirst(&b);
  list.AddFirst(&c);
  list.AddFirst(&d);

  EXPECT_EQ(4, *list.Get(0));
  EXPECT_EQ(3, *list.Get(1));
  EXPECT_EQ(2, *list.Get(2));
  EXPECT_EQ(1, *list.Get(3));
}

////////////////////////////////////////
// Add Last
////////////////////////////////////////
TEST(LinkedListTest, AddLast) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3, d = 4;
  list.AddLast(&a);
  list.AddLast(&b);
  list.AddLast(&c);
  list.AddLast(&d);

  EXPECT_EQ(1, *list.Get(0));
  EXPECT_EQ(2, *list.Get(1));
  EXPECT_EQ(3, *list.Get(2));
  EXPECT_EQ(4, *list.Get(3));
}

////////////////////////////////////////
// Get Index
////////////////////////////////////////
TEST(LinkedListTest, GetIndex) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(1, *list.Get(0));
  EXPECT_EQ(2, *list.Get(1));
  EXPECT_EQ(3, *list.Get(2));
}

TEST(LinkedListTest, GetIndexString) {
  LinkedList<std::string> list;

  std::string a = "Hello,";
  list.Add(&a);
  std::string b = "wonderful";
  list.Add(&b);
  std::string c = "world!";
  list.Add(&c);

  EXPECT_EQ("Hello,",    *list.Get(0));
  EXPECT_EQ("wonderful", *list.Get(1));
  EXPECT_EQ("world!",    *list.Get(2));
}

TEST(LinkedListTest, GetIndexShouldThrow) {
  LinkedList<int> list;
  bool failed = false;

  try {
    list.Get(0);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
  failed = false;

  try {
    list.Get(-1);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
  failed = false;

  int a = 1;
  list.Add(&a);

  try {
    list.Get(1);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
}

////////////////////////////////////////
// Get First
////////////////////////////////////////
TEST(LinkedListTest, GetFirst) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(1, *list.GetFirst());
}

TEST(LinkedListTest, GetFirstShouldThrow) {
  LinkedList<int> list;
  bool failed = false;

  try {
    list.GetFirst();
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
}

////////////////////////////////////////
// Get Last
////////////////////////////////////////
TEST(LinkedListTest, GetLast) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(3, *list.GetLast());
}

TEST(LinkedListTest, GetLastShouldThrow) {
  LinkedList<int> list;
  bool failed = false;

  try {
    list.GetLast();
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
}

////////////////////////////////////////
// Get Pointers
////////////////////////////////////////
TEST(LinkedListTest, GetPointersAreEqual) {
  LinkedList<int> list;

  int a = 1;
  list.Add(&a);

  EXPECT_EQ(*list.GetFirst(), *list.GetLast());
  EXPECT_EQ(list.GetFirst(), list.GetLast());
  EXPECT_EQ(list.GetFirst(), list.Get(0));
}

////////////////////////////////////////
// Remove Index
////////////////////////////////////////
TEST(LinkedListTest, RemoveIndexFront) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(1, *list.Remove(0));
  EXPECT_EQ(2, list.Size());

  EXPECT_EQ(2, *list.Remove(0));
  EXPECT_EQ(1, list.Size());

  EXPECT_EQ(3, *list.Remove(0));
  EXPECT_EQ(0, list.Size());
}

TEST(LinkedListTest, RemoveIndexBack) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(3, *list.Remove(2));
  EXPECT_EQ(2, list.Size());

  EXPECT_EQ(2, *list.Remove(1));
  EXPECT_EQ(1, list.Size());

  EXPECT_EQ(1, *list.Remove(0));
  EXPECT_EQ(0, list.Size());
}

TEST(LinkedListTest, RemoveIndexMiddle) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);
  list.Add(&c);

  EXPECT_EQ(2, *list.Remove(1));
  EXPECT_EQ(2, list.Size());

  EXPECT_EQ(3, *list.Remove(1));
  EXPECT_EQ(1, list.Size());

  EXPECT_EQ(1, *list.Remove(0));
  EXPECT_EQ(0, list.Size());
}

TEST(LinkedListTest, RemoveIndexShouldThrow) {
  LinkedList<int> list;
  bool failed = false;

  try {
    list.Remove(0);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
  failed = false;

  try {
    list.Remove(-1);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
  failed = false;

  int a = 1;
  list.Add(&a);

  try {
    list.Remove(1);
  } catch(std::exception& e) {
    failed = true;
  }

  EXPECT_TRUE(failed);
}

////////////////////////////////////////
// Remove Element
////////////////////////////////////////
TEST(LinkedListTest, RemoveElement) {
  LinkedList<int> list;

  int a = 1, b = 2, c = 3;
  list.Add(&a);
  list.Add(&b);

  EXPECT_TRUE(list.Remove(&a));
  EXPECT_EQ(1, list.Size());

  EXPECT_TRUE(list.Remove(&b));
  EXPECT_EQ(0, list.Size());

  EXPECT_FALSE(list.Remove(&c));
  EXPECT_EQ(0, list.Size());

  list.Add(&a);
  list.Add(&c);

  EXPECT_TRUE(list.Remove(&c));
  EXPECT_EQ(1, list.Size());

  EXPECT_EQ(1, *list.GetFirst());
  EXPECT_EQ(1, *list.GetLast());
}

////////////////////////////////////////
// Clear
////////////////////////////////////////
TEST(LinkedListTest, Clear) {
  LinkedList<int> list;

  int a = 1, b = 2;
  list.Add(&a);
  list.Add(&b);

  EXPECT_EQ(2, list.Size());

  list.Clear();

  EXPECT_EQ(0, list.Size());
}


////////////////////////////////////////
// Size
////////////////////////////////////////
TEST(LinkedListTest, ListSize) {
  LinkedList<int> list;
  EXPECT_EQ(0, list.Size());
  EXPECT_EQ(0, list.Size());

  int a = 1;
  list.Add(&a);
  EXPECT_EQ(1, list.Size());
  EXPECT_EQ(1, list.Size());

  list.Clear();
  EXPECT_EQ(0, list.Size());
  EXPECT_EQ(0, list.Size());
}

#endif  // LINKED_LIST_TEST_H_
