// Copyright 2014, Maximilian Fellner

#ifndef SORT_H_
#define SORT_H_

namespace mfellner {

class Sort {
 public:
   static void MergeSortRecursive(int, int[]);

   static void MergeSortIterative(int, int[]);

   static void ArrayPrint(int, int[], const char*);

 private:
   Sort() {}

   static void MSortSplit(int, int, int[]);

   static void MSortMerge(int, int, int, int[]);
};

}

#endif // SORT_H_
