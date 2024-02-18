#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method
/*
TEST_CASE("Test adding a non-allowable word", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]")
{
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test adding", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.add("a"));
	REQUIRE(b.add("aAa"));
	REQUIRE(b.add("Wxww"));
	REQUIRE(!b.add("a093824uwn"));
	REQUIRE(b.add("aBBBBBBBBAAA"));
	REQUIRE(b.add("ajdcjkncsdjkncds"));
	REQUIRE(!b.add("!ascasc"));
}

TEST_CASE("CutTest1#1", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"a"};
	REQUIRE(b.cutTest1(word));
}

TEST_CASE("CutTest1#2", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"ab"};
	REQUIRE(!b.cutTest1(word));
}

TEST_CASE("CutTest1#3", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"aAa"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#4", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"aAa"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#5", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"aAAAa"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#6", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"AaAAAaA"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#7", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"aaaa"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#8", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"AaaA"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#9", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"mnbbnm"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#10", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"MnbnM"};
	REQUIRE(b.cutTest1(word));
}
TEST_CASE("CutTest1#11", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"AaaA","vvavv"};
	REQUIRE(b.cutTest1(word));
}

TEST_CASE("listPalindromes#1", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("a");
	b.add("AA");
	b.add("AaA");
	REQUIRE(b.cutTest1({"a","AA","AaA"}));

	b.toVector();
	
}

TEST_CASE("CutTest1#12", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> word;
	word = {"AaaA","avava","WrWrW"};
	REQUIRE(!b.cutTest1(word));
}	
TEST_CASE("recursiveTest#1", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("ate");
	b.add("Owl");
	b.add("Mr");
	b.add("my");
	b.add("worm");
	b.add("metal");
	REQUIRE(b.number()==1);
}
TEST_CASE("recursiveTest#2", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("12");
	REQUIRE(b.number()==0);
}		
TEST_CASE("recursiveTest N!", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("aAa");
	b.add("AAA");
	b.add("aaa");
	REQUIRE(b.number()==6);
}	

TEST_CASE("Constructor", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.number() == 0);
}		
TEST_CASE("Number Test", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.number() == 0);
	b.add("aaa");
	b.add("AAA");
	REQUIRE(b.number()==2);
}
TEST_CASE("Clear Test", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("aaaa");
	b.add("AAAA");
	b.add("1234");
	b.clear();
	REQUIRE(b.number()==0);
}
*/
TEST_CASE("Cut Test 2", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v1,v2;
	v1 = {"AaA", "AAA"};
	v2 = {"AaA", "AAA"};
	
	REQUIRE(b.cutTest2(v1,v2));
}
TEST_CASE("Cut Test 2 #2 invalid", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v1,v2;
	v1 = {"AAA", "AAA"};
	v2 = {"AAA", "AAz"};
	
	REQUIRE(!b.cutTest2(v1,v2));
}
TEST_CASE("Cut Test 2 #3", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v1,v2;
	v1 = {"AzAA", "zAAA"};
	v2 = {"AAAz", "AAzA"};
	
	REQUIRE(b.cutTest2(v1,v2));
}
TEST_CASE("Cut Test 2 #4 invalid", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v1,v2;
	v1 = {"AzAA", "zAAA"};
	v2 = {"AAAz", "AAzAA"};
	
	REQUIRE(!b.cutTest2(v1,v2));
}
TEST_CASE("Cut Test 2 #5 invalid", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v1,v2;
	v1 = {"never", "odd"};
	v2 = {"or", "even"};
	
	REQUIRE(b.cutTest2(v1,v2));
}
