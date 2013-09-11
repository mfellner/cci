// Copyright 2013, Maximilian Fellner

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>

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
     ListElement* element = NewListElement(e);

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
     if (index < 0)
       throw std::out_of_range(StringWithInt("invalid index ", index));

     ListElement* element = NewListElement(e);

     if (head_ && index > 0) {
       ListElement* before = head_;
       for (int i = 1; i < index; i++) {
         before = before->next;
         if ((!before && i < index) || (!before->next && i + 1 < index))
           throw std::out_of_range(StringWithInt("invalid index ", index));
       }
       element->next = before->next;
       before->next = element;
     } else if (head_ && index == 0) {
       element->next = head_;
       head_ = element;
     } else if (!head_ && index == 0) {
       head_ = element;
     } else {
       throw std::out_of_range(StringWithInt("invalid index ", index));
     }
   }

   // Inserts the specified element at the beginning of this list.
   void AddFirst(E* e) {
     ListElement* element = NewListElement(e);

     if (head_) {
       element->next = head_;
       head_ = element;
     } else {
       head_ = element;
     } 
   }

   // Appends the specified element to the end of this list.
   void AddLast(E* e) {
     ListElement* element = NewListElement(e);

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
   E* Get(int index) {
     if (index < 0)
       throw std::out_of_range(StringWithInt("invalid index ", index));

     if (head_ && index > 0) {
       ListElement* element = head_;
       for (int i = 1; i <= index; i++) {
         element = element->next;
         if (!element)
           throw std::out_of_range(StringWithInt("invalid index ", index));
       }
       return element->data;
     } else if (head_ && index == 0) {
       return head_->data;
     } else {
       throw std::out_of_range(StringWithInt("invalid index ", index));
     }
   }

   // Returns the first element in this list.
   E* GetFirst() {
     if (!head_) throw std::out_of_range("no such element");
     return head_->data;
   }

   // Returns the last element in this list.
   E* GetLast() {
     if (!head_) throw std::out_of_range("no such element");

     ListElement* tail = head_;
     while (tail->next) {
       tail = tail->next;
     }
     return tail->data;
   }

   // Removes the element at the specified position in this list.
   E* Remove(int index) {
     if (index < 0)
       throw std::out_of_range(StringWithInt("invalid index ", index));
   
     if (head_ && index > 0) {
       ListElement* element = head_;
       ListElement* before  = 0;
       for (int i = 1; i <= index; i++) {
         before  = element;
         element = element->next;
         if (!element)
           throw std::out_of_range(StringWithInt("invalid index ", index));
       }
       ListElement* next = element->next;
       E* data           = element->data;
       delete element;
       before->next      = next;
       return data;
     } else if (head_ && index == 0) {
       ListElement* next = head_->next;
       E* data           = head_->data;
       delete head_;
       head_             = next;
       return data;
     } else {
       throw std::out_of_range(StringWithInt("invalid index ", index));
     }
   }

   // Removes the first occurrence of the specified element from this list, if it is present.
   bool Remove(E* e) {
     if (head_ && *(head_->data) == *e) {
       ListElement* next = head_->next;
       delete head_;
       head_ = next;
       return true;
     }

     ListElement* element = head_;
     ListElement* before  = 0;

     while (element) {
       if (*(element->data) == *e) {
         before->next = element->next;
         delete element;
         return true;
       }
       before  = element;
       element = element->next;
     }
     return false;
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
   // An element in the linked list.
   typedef struct ListElement {
     ListElement* next;
     E* data;
   } ListElement;

   ListElement* head_;

   // No copies.
   LinkedList(const LinkedList& l) {}

   ListElement* NewListElement(E* e) {
     ListElement* element = new ListElement();
     element->next = 0;
     element->data = e;
     return element;
   }

   std::string StringWithInt(std::string s, int i) {
     std::stringstream stream;
     stream << s << i;
     return stream.str();
   }
};

}

#endif  // LINKED_LIST_H_
