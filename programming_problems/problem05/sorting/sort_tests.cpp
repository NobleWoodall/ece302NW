#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
#include "sort.hpp"

// write your test cases here
TEST_CASE("Test case", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 4);
  REQUIRE(sorted.getEntry(1) == 10);
  REQUIRE(sorted.getEntry(2) == 11);
  REQUIRE(sorted.getEntry(3) == 25);
  REQUIRE(sorted.getEntry(4) == 100);
  
}
// write your test cases here
TEST_CASE("Test case single character", "sorting"){

  LinkedList<char> lst;

  lst.insert(0, 'b');
  lst.insert(1, 'c');
  lst.insert(2, 'd');
  lst.insert(3, 'e');
  lst.insert(4, 'a');

  LinkedList<char> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 'a');
  REQUIRE(sorted.getEntry(1) == 'b');
  REQUIRE(sorted.getEntry(2) == 'c');
  REQUIRE(sorted.getEntry(3) == 'd');
  REQUIRE(sorted.getEntry(4) == 'e');
  
}
TEST_CASE("Test case strings multiple character", "sorting"){

  LinkedList<std::string> lst;

  lst.insert(0, "bees");
  lst.insert(1, "cartoons");
  lst.insert(2, "dogs");
  lst.insert(3, "elephants");
  lst.insert(4, "anime");

  LinkedList<std::string> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == "anime");
  REQUIRE(sorted.getEntry(1) == "bees");
  REQUIRE(sorted.getEntry(2) == "cartoons");
  REQUIRE(sorted.getEntry(3) == "dogs");
  REQUIRE(sorted.getEntry(4) == "elephants");
  
}

TEST_CASE("Test case equivalent", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 0);
  lst.insert(1, 0);
  lst.insert(2, 0);
  lst.insert(3, 0);
  lst.insert(4, 0);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 0);
  REQUIRE(sorted.getEntry(1) == 0);
  REQUIRE(sorted.getEntry(2) == 0);
  REQUIRE(sorted.getEntry(3) == 0);
  REQUIRE(sorted.getEntry(4) == 0);
  
}
TEST_CASE("Test case double and negative", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 11);
  lst.insert(1, -11);
  lst.insert(2, 5);
  lst.insert(3, 3);
  lst.insert(4, -2);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == -11);
  REQUIRE(sorted.getEntry(1) == -2);
  REQUIRE(sorted.getEntry(2) == 3);
  REQUIRE(sorted.getEntry(3) == 5);
  REQUIRE(sorted.getEntry(4) == 11);
  
}