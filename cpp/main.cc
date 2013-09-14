// Copyright 2013, Maximilian Fellner

#include "gtest/gtest.h"

#include "linked-list-test.h"
#include "sort-test.h"
#include "tree-test.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
