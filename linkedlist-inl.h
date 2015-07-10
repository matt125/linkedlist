#include <stdexcept>

#include "linkedlist.h"

/*/////////////////////////////////////////////////////////////////////////////
// constructors/destructors ///////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////////

template <typename item>
LinkedList<item>::LinkedList() {
  head = NULL;
  length = 0;
}

template <typename item>
LinkedList<item>::~LinkedList() {
  clear();
}

/*/////////////////////////////////////////////////////////////////////////////
// Insertions /////////////////////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////////

template <typename item>
void LinkedList<item>::insert_initial(item new_item) {
  head = new Node;
  head->value = new_item;
  head->next = head;
  head->prev = head;
  length = 1;
}

template <typename item>
void LinkedList<item>::insert_node(Node* ins, Node* next) {
  ins->next = next;
  ins->prev = next->prev;
  next->prev->next = ins;
  next->prev = ins;
  if (next == head) {
    head = ins;
  }
  length++;
}

template <typename item>
void LinkedList<item>::insert(item new_item) {
  insert_back(new_item);
}

template <typename item>
void LinkedList<item>::insert(item new_item, unsigned index) {
  if (index >= length) {
    return insert_back(new_item);
  } else if (length == 0) {
    return insert_initial(new_item);
  } else {
    Node *curr = head;
    for (unsigned i = 0; i < index; i++) {
      curr = curr->next;
    }
    insert_node(new Node(new_item), curr);
  }
}

template <typename item>
void LinkedList<item>::insert_front(item new_item) {
  if (length == 0) {
    return insert_initial(new_item);
  } else {
    insert_node(new Node(new_item), head);
  }
}

template <typename item>
void LinkedList<item>::insert_back(item new_item) {
  if (length == 0) {
    return insert_initial(new_item);
  } else {
    Node *new_node = new Node(new_item, head->prev, head);
    head->prev->next = new_node;
    head->prev = new_node;
    length++;
  }
}

template <typename item> template <typename... Args>
void LinkedList<item>::emplace(unsigned index, Args&&... args) {
  Node *new_node = new Node(head->prev, head, std::forward<Args>(args)...);
}

/*/////////////////////////////////////////////////////////////////////////////
// Removals ///////////////////////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////////

template <typename item>
void LinkedList<item>::delete_node(Node *node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  if (node == head) {
    head = head->next;
  }
  delete node;
  length--;
  if (length == 0) {
    head = NULL;
  }
}

template <typename item>
void LinkedList<item>::remove(item it) {
  if (length == 0) {
    return;
  }
  Node *curr = head;
  for (unsigned i = 0; i < length-1; i++) {
    if (curr->value == it) {
      delete_node(curr);
    }
    curr = curr->next;
  }
  if (length == 0) {
    head = NULL;
  }
}

template <typename item>
void LinkedList<item>::remove_index(unsigned index) {
  if (index < 0 || index >= length) {
    throw std::out_of_range("Removal index does not exist\n");
  }
  Node *curr = head;
  for (unsigned i = 0; i < index; i++) {
    curr = curr->next;
  }
  delete_node(curr);
}

template <typename item>
void LinkedList<item>::remove_back() {
  if (length == 0) {
    throw std::out_of_range("Removal index does not exist\n");
  }
  delete_node(head->prev);
}

template <typename item>
void LinkedList<item>::remove_front() {
  if (length == 0) {
    throw std::out_of_range("Removal index does not exist\n");
  }
  delete_node(head);
}

/*/////////////////////////////////////////////////////////////////////////////
// Access /////////////////////////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////////


// This function has undefined behavior if used improperly. This is a design
// choice because most programmers are used to brackets providing undefined
// behavior if used improperly.
template <typename item>
item& LinkedList<item>::operator[](int index) {
  Node *curr = head;
  for (int i = 0; i < index; i++) {
    curr = curr->next;
  }
  return curr->value;
}

// This function on the other hand will throw an exception if used improperly.
template <typename item>
item& LinkedList<item>::at(unsigned index) {
  if (index >= length) {
    throw std::out_of_range("index is not valid\n");
  }
  Node *curr = head;
  for (unsigned i = 0; i < index; i++) {
    curr = curr->next;
  }
  return curr->value;
}

template <typename item>
item& LinkedList<item>::front() {
  if (length == 0) {
    throw std::out_of_range("index is not valid\n");
  }
  return head->value;
}

template <typename item>
item& LinkedList<item>::back() {
  if (length == 0) {
    throw std::out_of_range("index is not valid\n");
  }
  return head->prev->value;
}

/*/////////////////////////////////////////////////////////////////////////////
// Utility ////////////////////////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////////

template <typename item>
void LinkedList<item>::clear() {
  if (length == 0) {
    return;
  }
  Node *curr = head;
  for (unsigned i = 0; i < length; i++) {
    Node *next = curr->next;
    delete curr;
    curr = next;
  }
  head = NULL;
  length = 0;
}

template <typename item>
unsigned LinkedList<item>::size() {
  return length;
}
