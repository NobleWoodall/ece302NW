#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("ConstructorTest", "[DynamicBag]"){
  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize()==0);
}
TEST_CASE("Copy Constructor Test","[DynamicBag]"){
  DynamicBag<int> b;
  b.add(1);

  DynamicBag<int> c = b;
  REQUIRE(c.contains(1));

}
TEST_CASE("Overlaoded Equal Test","[DynamicBag]"){
  DynamicBag<int> b;
  b.add(1);

  DynamicBag<int> c;
  c.add(2);

  b = c;

  REQUIRE(b.contains(2));
  
}
TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}


TEST_CASE("Add test", "[DynamicBag]"){
  DynamicBag<int> b;
  
  b.add(1);
  REQUIRE_FALSE(b.isEmpty());
  REQUIRE(b.contains(1));
  REQUIRE(b.getCurrentSize()==1);
}

TEST_CASE("Empty test", "[DynamicBag]"){
  DynamicBag<int> b;
  b.clear();
  REQUIRE(b.isEmpty());
}

TEST_CASE("Remove test", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(1);
  b.remove(1);
  REQUIRE_FALSE(b.contains(1));
  REQUIRE(b.getCurrentSize()==0);
}
TEST_CASE("GetSize test", "[DynamicBag]"){
  DynamicBag<int> b;
  b.clear();
  b.add(1);
  b.add(-1);
  b.add(3);
  b.remove(3);
  REQUIRE(b.getCurrentSize()==2);
}
TEST_CASE("Contains test", "[DynamicBag]"){
  DynamicBag<int> b;
  b.clear();
  b.add(1);
  b.add(-1);
  b.add(3);
  b.remove(3);
  REQUIRE(b.contains(-1));
  REQUIRE(b.contains(1));
  REQUIRE_FALSE(b.contains(3));
}
TEST_CASE("Clear test", "[DynamicBag]"){
  DynamicBag<int> b;
  b.clear();
  b.add(1);
  b.add(-1);
  b.add(3);
  b.remove(3);
  b.clear();
  REQUIRE_FALSE(b.contains(-1));
  REQUIRE_FALSE(b.contains(1));
  REQUIRE_FALSE(b.contains(3));
  REQUIRE(b.getCurrentSize()==0);
}
TEST_CASE("GetFreq test", "[DynamicBag]"){
  DynamicBag<int> b;
  b.clear();
  b.add(1);
  b.add(1);
  b.add(1);
  b.remove(1);

  REQUIRE(b.getFrequencyOf(1)==2);
}
