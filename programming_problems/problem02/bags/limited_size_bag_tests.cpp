#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("ConstructorTest", "[LimitedBag]"){
  LimitedSizeBag<int> b;
  REQUIRE(b.getCurrentSize()==0);
}
TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}

TEST_CASE("Add test", "[LimitedBag]"){
  LimitedSizeBag<int> b;
  b.add(1);
  REQUIRE_FALSE(b.isEmpty());
  REQUIRE(b.contains(1));
  REQUIRE(b.getCurrentSize()==1);
}

TEST_CASE("Remove test", "[LimitedBag]"){
  LimitedSizeBag<int> b;
  b.add(1);
  b.remove(1);
  REQUIRE_FALSE(b.contains(1));
  REQUIRE(b.getCurrentSize()==0);
}
TEST_CASE("Empty test", "[LimitedBag]"){
  LimitedSizeBag<int> b;
  b.clear();
  REQUIRE(b.isEmpty());
}
TEST_CASE("GetSize test", "[LimitedBag]"){
  LimitedSizeBag<int> b;
  b.clear();
  b.add(1);
  b.add(-1);
  b.add(3);
  b.remove(3);
  REQUIRE(b.getCurrentSize()==2);
}
TEST_CASE("Contains test", "[LimitedBag]"){
  LimitedSizeBag<int> b;
  b.clear();
  b.add(1);
  b.add(-1);
  b.add(3);
  b.remove(3);
  REQUIRE(b.contains(-1));
  REQUIRE(b.contains(1));
  REQUIRE_FALSE(b.contains(3));
}
TEST_CASE("Clear test", "[LimitedBag]"){
  LimitedSizeBag<int> b;
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
TEST_CASE("GetFreq test", "[LimitedBag]"){
  LimitedSizeBag<int> b;
  b.clear();
  b.add(1);
  b.add(1);
  b.add(1);
  b.remove(1);

  REQUIRE(b.getFrequencyOf(1)==2);
 }

