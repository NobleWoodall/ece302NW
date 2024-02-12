#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <iostream>
#include "bitset.hpp"

TEST_CASE("Test bitset default construction", "[bitset]")
{
    Bitset b;
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
   
}

TEST_CASE("Test bitset construction with asString", "[bitset]")
{
    Bitset b;
    REQUIRE(b.asString().compare("00000000") == 0);
}

TEST_CASE("Test bitset construction size", "[bitset]")
{
    Bitset b(64);
    std::string s(64, '0');
    REQUIRE(b.size() == 64);
    REQUIRE(b.good());
}

TEST_CASE("Test bitset construction string", "[bitset]")
{
    std::string s("00101110000011000001101000001");
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE("Test bitset construction invalid string", "[bitset]")
{
    std::string s("00101110000011002001101000001");
    Bitset b(s);
    REQUIRE_FALSE(b.good());
}

TEST_CASE("Test set", "[bitset]")
{
    std::string s("00010001");
    Bitset b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE("Test set with size init", "[bitset]")
{
    std::string s("00010");
    Bitset b(5);
    b.set(3);
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE("Test combined", "[bitset]")
{
    std::string s((1 << 15) + 3, '1');
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1 << 10); i++)
    {
        b.set(i);
        b.reset(i + (1 << 10));
        b.toggle(i + (1 << 11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1 << 10)));
        REQUIRE(((b.test(i + (1 << 11)) == true && s.at(i + (1 << 11)) == '0') || (b.test(i + (1 << 11)) == false && s.at(i + (1 << 11)) == '1')));
    }
}










TEST_CASE("Test bitset default construction when invalid", "[bitset]")
{
   Bitset b;
   REQUIRE_FALSE(b.size() != 8);
   REQUIRE(b.good());
}

TEST_CASE("Test bitset construction with string being 1", "[bitset]")
{
    Bitset b;
    REQUIRE_FALSE(b.asString().compare("00000001") == 0);

}

TEST_CASE("Test bitset construction size when 0", "[bitset]")
{
    Bitset b(0);
    std::string s(64, '0');
    REQUIRE(b.size() == 0);
    REQUIRE_FALSE(b.good());
}

TEST_CASE("Test bitset construction string when string passed directly", "[bitset]")
{

    Bitset b("00101110000011000001101000001");
    
    REQUIRE(b.good());
    REQUIRE(b.asString().compare("00101110000011000001101000001") == 0);
}

TEST_CASE("Test bitset construction invalid string of letters", "[bitset]")
{
    std::string s("oneoneoneoneonezerozerotwoOHNOINIVALID");
    Bitset b(s);
    REQUIRE_FALSE(b.good());
}

TEST_CASE("Test set 2 all bits", "[bitset]")
{
    std::string s("11111111");
    Bitset b;
    b.set(0);
    b.set(1);
    b.set(2);
    b.set(3);
    b.set(4);
    b.set(5);
    b.set(6);
    b.set(7);

    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE("Test set with size when negative", "[bitset]")
{
    Bitset b(-1);
    REQUIRE_FALSE(b.good());
}

TEST_CASE("Test combined 2", "[bitset]")
{
    std::string s((1 << 15) + 3, '0');
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1 << 10); i++)
    {
        b.set(i);
        b.reset(i + (1 << 10));
        b.toggle(i + (1 << 11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1 << 10)));
        REQUIRE(((b.test(i + (1 << 11)) == true && s.at(i + (1 << 11)) == '0') || (b.test(i + (1 << 11)) == false && s.at(i + (1 << 11)) == '1')));
    }
}