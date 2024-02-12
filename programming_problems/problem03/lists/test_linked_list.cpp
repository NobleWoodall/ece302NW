#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "linked_list.hpp"

// force class expansion
template class LinkedList<int>;

TEST_CASE("Test Default", "[LinkedList]")
{
  LinkedList<int> list;
  REQUIRE(list.getLength() == 0);

}
TEST_CASE("Test Copy Constructor", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(0,1);
  
  LinkedList<int> list2 = list;
  REQUIRE(list2.getLength()==1);

}
TEST_CASE("Test Overloaded =", "[LinkedList]")
{

  LinkedList<int> list;
  list.insert(0,-1);
  list.insert(1,-1);

  LinkedList<int> list2;
  list2.insert(0,-1);

  list2=list;

  REQUIRE(list2.getLength() == 2);

}
TEST_CASE("Test Swap", "[LinkedList]")
{

  LinkedList<int> list;
  
}
TEST_CASE("Test isEmpty", "[LinkedList]")
{

  LinkedList<int> list;
  REQUIRE(list.isEmpty());

  list.insert(0,1);

  REQUIRE_FALSE(list.isEmpty());

}
TEST_CASE("Test GetLegnth", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0,1);
  list.insert(1,1);
  list.insert(2,1);
  list.insert(3,1);

  REQUIRE(list.getLength()==4);

  list.clear();

  REQUIRE(list.getLength()==0);

}
TEST_CASE("Test Insert", "[LinkedList]")
{

  LinkedList<int> list;

}
TEST_CASE("Test Remove", "[LinkedList]")
{

  LinkedList<int> list;
  list.insert(0,11);
  list.remove(0);

  REQUIRE(list.getLength()==0);

}
TEST_CASE("Test Clear", "[LinkedList]")
{

  LinkedList<int> list;
  list.insert(0,11);
  list.insert(1,11);
  list.insert(2,11);
  list.insert(3,11);
  list.insert(4,11);
  list.insert(5,11);
    
  list.clear();

  REQUIRE(list.getLength()==0);


}
TEST_CASE("Test getEmpty", "[LinkedList]")
{

  LinkedList<int> list;
  REQUIRE(list.isEmpty());

  list.insert(0,1);

  REQUIRE_FALSE(list.isEmpty());

}
TEST_CASE("Test setEntry", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0,12345);
  list.setEntry(0,999);

  REQUIRE(list.getEntry(0)==999);

}
TEST_CASE("Test getEntry after Remove and after Insert", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0,12345);
  list.insert(1,234);
  list.insert(2,1232);
  
  list.remove(1);
  
  REQUIRE(list.getEntry(1)==1232);

}

