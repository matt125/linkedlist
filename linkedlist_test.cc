#include "gtest/gtest.h"
#include "linkedlist.h"

TEST(LinkedList, sanity) {
  LinkedList<int> ll1;
  ll1.insert_front(5);
}

TEST(LinkedList, insertions) {
  LinkedList<int> ll1;

  ll1.insert_front(5);
  EXPECT_EQ(ll1[0], 5);
  EXPECT_EQ(ll1.size(), 1);
  ll1.insert_front(4);
  EXPECT_EQ(ll1[0], 4);
  EXPECT_EQ(ll1[1], 5);
  EXPECT_EQ(ll1.size(), 2);

  ll1.insert_back(6);
  EXPECT_EQ(ll1[0], 4);
  EXPECT_EQ(ll1[1], 5);
  EXPECT_EQ(ll1[2], 6);
  EXPECT_EQ(ll1.size(), 3);

  ll1.insert(3, 0);
  EXPECT_EQ(ll1[0], 3);
  EXPECT_EQ(ll1.size(), 4);

  ll1.insert(7, ll1.size());
  EXPECT_EQ(ll1[ll1.size()-1], 7);

  ll1.insert(17, 1);
  EXPECT_EQ(ll1[1], 17);
  EXPECT_EQ(ll1.size(), 6);
}

TEST(LinkedList, access) {
  LinkedList<int> ll1;
  for (int i = 0; i < 20; i++) {
    ll1.insert_back(i);
    EXPECT_EQ(ll1[i], i);
    EXPECT_EQ(ll1.at(i), i);
    EXPECT_THROW(ll1.at(i+1), std::out_of_range);
  }
}

TEST(LinkedList, removals) {
  LinkedList<int> ll1;
  LinkedList<int> ll2; LinkedList<int> ll3;
  for (int i = 0; i < 10; i++) {
    ll1.insert_back(i);
    ll2.insert_back(i);
    ll3.insert_back(i);
  }

  ll1.remove(5);
  EXPECT_EQ(ll1[5], 6);
  ll1.remove(0);
  EXPECT_EQ(ll1[0], 1);
  ll1.remove(9);
  EXPECT_EQ(ll1[6], 8);

  ll2.remove_index(0);
  EXPECT_EQ(ll1[0], 1);
  ll2.remove_index(7);
  EXPECT_EQ(ll1[7], 9);
  ll2.remove_index(4);
  EXPECT_EQ(ll1[4], 6);

  ll3.remove_front();
  EXPECT_EQ(ll1[0], 1);
  ll3.remove_front();
  EXPECT_EQ(ll1[7], 9);
  ll3.remove_back();
  EXPECT_EQ(ll3[6], 8);
  EXPECT_EQ(ll3.size(), 7);
  ll3.remove_back();
  EXPECT_EQ(ll3[5], 7);
  EXPECT_EQ(ll3.size(), 6);
}

TEST(LinkedList, utility) {
  LinkedList<int> ll1;
  for (int i = 0; i < 10; i++) {
    ll1.insert_back(i);
  }
  EXPECT_EQ(ll1.size(), 10);
  ll1.clear();
  EXPECT_EQ(ll1.size(), 0);
  for (int i = 0; i < 10; i++) {
    ll1.insert_back(i);
    EXPECT_EQ(ll1[i], i);
  }
}

