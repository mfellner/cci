// Copyright 2013, Maximilian Fellner

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

namespace mfellner {

template <class E>
class LinkedList {
 public:
   // Appends the specified element to the end of this list.
   bool Add(E* e);

   // Inserts the specified element at the specified position in this list.
   void Add(int index, E* e);
   
   // Inserts the specified element at the beginning of this list.
   void AddFirst(E* e);
   
   // Appends the specified element to the end of this list.
   void AddLast(E* e);
   
   // Removes all of the elements from this list.
   void Clear();
   
   // Returns the element at the specified position in this list.
   E* Get(int index);
   
   // Returns the first element in this list.
   E* GetFirst();
   
   // Returns the last element in this list.
   E* GetLast();

 private:
   // An element in the linked list.
   typedef struct ListElement {
     E* next;
     E* data;
   } ListElement;
};

}

#endif  // LINKED_LIST_H_
