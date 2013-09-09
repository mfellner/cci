// Copyright 2013, Maximilian Fellner

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <exception>

namespace mfellner {

template <class E>
class LinkedList {
 public:
    LinkedList() : head_(0) {}

   ~LinkedList() {
     ListElement* tail = head_;
     head_ = 0;

     while (tail) {
       ListElement* element = tail;
       tail = tail->next;
       delete element;
       element = 0;
     }
   }

   // Appends the specified element to the end of this list.
   void Add(E* e) {
     ListElement* element = new ListElement();
     element->next = 0;
     element->data = e;

     if (head_) {
       ListElement* tail = head_;
       while (tail->next) {
         tail = tail->next;
       }
       tail->next = element;
     } else {
       head_ = element;
     }
   }

   // Inserts the specified element at the specified position in this list.
   void Add(int index, E* e) {
     throw std::exception();
   }

   // Inserts the specified element at the beginning of this list.
   void AddFirst(E* e) {
     throw std::exception();
   }

   // Appends the specified element to the end of this list.
   void AddLast(E* e) {
     throw std::exception();
   }

   // Removes all of the elements from this list.
   void Clear() {
     ListElement* tail = head_;
     head_ = 0;

     while (tail) {
       ListElement* element = tail;
       tail = tail->next;
       delete element;
       element = 0;
     }
   }

   // Returns the element at the specified position in this list.
   E* Get(int) {
     throw std::exception();
   }

   // Returns the first element in this list.
   E* GetFirst() {
     return head_ ? head_->data : 0;
   }

   // Returns the last element in this list.
   E* GetLast() {
     if (!head_) return 0;

     ListElement* tail = head_;

     while (tail->next) {
       tail = tail->next;
     }
     return tail->data;
   }

   // Returns the number of elements in this list.
   int Size() {
     int size = 0;
     ListElement* tail = head_;

     while (tail) {
       tail = tail->next;
       size++;
     }
     return size;
   }

 private:
   // No copies.
   LinkedList(const LinkedList& l) {}

   // An element in the linked list.
   typedef struct ListElement {
     ListElement* next;
     E* data;
   } ListElement;

   ListElement* head_;
};

// template <class E>
// void LinkedList<E>::Add(E* e) {
//   throw std::exception();
// }

}

#endif  // LINKED_LIST_H_
