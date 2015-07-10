#include <iostream>

#include "linkedlist.h"

int main() {
  LinkedList<int> l1;
  l1.insert_back(5);
  l1.insert_back(4);
  l1.insert_back(3);
  l1.insert_back(2);
  l1.insert_back(1);
  for (int i = 0; i < l1.size(); i++) {
    std::cout << l1[i] << std::endl;
  }
  l1.remove(5);
  for (int i = 0; i < l1.size(); i++) {
    std::cout << l1[i] << std::endl;
  }
  l1.remove_back();
  for (int i = 0; i < l1.size(); i++) {
    std::cout << l1[i] << std::endl;
  }
  l1.remove_front();
  for (int i = 0; i < l1.size(); i++) {
    std::cout << l1[i] << std::endl;
  }
  return 0;
}
