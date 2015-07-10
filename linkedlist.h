#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

template <typename item>
class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  // Insertions
  void insert(item new_item);
  void insert(item new_item, unsigned index);
  void insert_front(item new_item);
  void insert_back(item new_item);
  template <typename... Args>
  void emplace(unsigned index, Args&&... args);

  // Removals
  void remove(item it);
  void remove_index(unsigned index);
  void remove_back();
  void remove_front();

  // Access
  item& operator[](int index);
  item& at(unsigned index);
  item& front();
  item& back();

  // Utility
  void clear();
  unsigned size();

 private:
  // a private node implementation for the LinkedList.
  typedef struct Node {
    Node() {};
    Node(item new_item) : value(new_item) {}
    Node(item v, Node *p, Node *n) : value(v), prev(p), next(n) {}
    template <typename... Args>
    Node(Node *p, Node *n, Args&&... args) : 
      prev(p),
      next(n),
      value(std::forward<Args>(args)...) {}
    item value;
    Node *prev;
    Node *next;
  } Node;

  Node *head;
  item *array;
  unsigned length;

  void insert_initial(item new_item);
  void insert_node(Node* ins, Node* next);
  void delete_node(Node *node);

  LinkedList(const LinkedList&);
  void operator=(const LinkedList&);
};

#include "linkedlist-inl.h"

#endif //LINKED_LIST_HEADER
