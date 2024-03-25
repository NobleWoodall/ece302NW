#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing Priority Queue isEmpty", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  REQUIRE(pq.isEmpty() == true);

  pq.add('a');
  REQUIRE(pq.isEmpty() == false);

  pq.remove();
  REQUIRE(pq.isEmpty() == true);

  pq.add(0);
  REQUIRE(pq.isEmpty() == false);

  pq.remove();
  REQUIRE(pq.isEmpty() == true);

  pq.add(-1);
  REQUIRE(pq.isEmpty() == false);

  pq.remove();
  REQUIRE(pq.isEmpty() == true);

  pq.add(1.2345);
  REQUIRE(pq.isEmpty() == false);

  pq.remove();
  REQUIRE(pq.isEmpty() == true);
  
}

TEST_CASE("Testing Priority Queue add", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  pq.add('a');
  REQUIRE(pq.isEmpty() == false);

  pq.remove();
  REQUIRE(pq.isEmpty() == true);

}
//THIS TESTING INSERT IS FOR TESTING ADD
TEST_CASE("Testing insert", "[sorted linked list]") {
  typedef SortedList<int, List<int>> SortedListType;
  
  SortedListType lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst.getEntry(i) == 'a' + i);
  }
} 


TEST_CASE("Testing Priority Queue remove", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  pq.add('b');
  pq.add('a');
  pq.add('d');
  pq.add('e');
  pq.add('f');
  pq.add('c');

  pq.remove();
    pq.remove();
      pq.remove();
        pq.remove();
          pq.remove();
            pq.remove();

  REQUIRE(pq.isEmpty() == true);

}

TEST_CASE("Testing Priority Queue remove through List", "[priority queue]") {
  typedef List<int> ListType;
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  ListType pq;

  pq.insert(0,'b');
  pq.insert(1,'a');
  pq.insert(2,'d');
  pq.insert(3,'e');
  pq.insert(4,'f');
  pq.insert(5,'c');

  pq.remove(pq.getLength() -1);


  CHECK_THROWS_AS(pq.getEntry(5), std::range_error);
}


TEST_CASE("Testing Priority Queue peek", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(1);
  pq.add(2);
  pq.add(4);
  pq.add(3);

  REQUIRE(pq.peek() == 4);

  pq.remove();
  REQUIRE(pq.peek() == 3);

  PriorityQueueType pqc;
  pq.add('a');
  pq.add('b');
  pq.add('c');
  pq.add('d');

  REQUIRE(pq.peek() == 'd');

  pq.remove();
  REQUIRE(pq.peek() == 'c');
}
