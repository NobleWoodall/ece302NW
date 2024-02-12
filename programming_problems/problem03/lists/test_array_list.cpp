#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "array_list.hpp"

// force class expansion
template class ArrayList<int>;

TEST_CASE("Test Default", "[ArrayList]")
{
  ArrayList<int> list;
  REQUIRE(list.getLength() == 0);

}
TEST_CASE("Test Copy Constructor", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0,1);
  
  ArrayList<int> list2 = list;
  REQUIRE(list2.getLength()==1);

}
TEST_CASE("Test Overloaded =", "[ArrayList]")
{

  ArrayList<int> list;
  list.insert(0,-1);
  list.insert(1,-1);

  ArrayList<int> list2;
  list2.insert(0,-1);

  list2=list;

  REQUIRE(list2.getLength() == 2);

}
TEST_CASE("Test Swap", "[ArrayList]")
{

  ArrayList<int> list;
  
}
TEST_CASE("Test isEmpty", "[ArrayList]")
{

  ArrayList<int> list;
  REQUIRE(list.isEmpty());

  list.insert(0,1);

  REQUIRE_FALSE(list.isEmpty());

}
TEST_CASE("Test GetLegnth", "[ArrayList]")
{

  ArrayList<int> list;

  list.insert(0,1);
  list.insert(1,1);
  list.insert(2,1);
  list.insert(3,1);

  REQUIRE(list.getLength()==4);

  list.clear();

  REQUIRE(list.getLength()==0);

}
TEST_CASE("Test Insert", "[ArrayList]")
{

  ArrayList<int> list;

}
TEST_CASE("Test Remove", "[ArrayList]")
{

  ArrayList<int> list;
  list.insert(0,11);
  list.remove(0);

  REQUIRE(list.getLength()==0);

}
TEST_CASE("Test Clear", "[ArrayList]")
{

  ArrayList<int> list;
  list.insert(0,11);
  list.insert(1,11);
  list.insert(2,11);
  list.insert(3,11);
  list.insert(4,11);
  list.insert(5,11);
    
  list.clear();

  REQUIRE(list.getLength()==0);


}
TEST_CASE("Test getEmpty", "[ArrayList]")
{

  ArrayList<int> list;
  REQUIRE(list.isEmpty());

  list.insert(0,1);

  REQUIRE_FALSE(list.isEmpty());

}
TEST_CASE("Test setEntry", "[ArrayList]")
{

  ArrayList<int> list;

  list.insert(0,12345);
  list.setEntry(0,999);

  REQUIRE(list.getEntry(0)==999);

}
