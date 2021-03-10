/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Shoshana Levin>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	input.erase(remove(input.begin(),input.end(),' '),input.end());
    input.erase(remove(input.begin(),input.end(),'\n'),input.end());
    input.erase(remove(input.begin(),input.end(),'\t'),input.end());
    input.erase(remove(input.begin(),input.end(),'\r'),input.end());
	return input;
}

TEST_CASE("Good snowman code") {
//HAT TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(21111111)) == nospaces(string("  ___\n .....\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(31111111)) == nospaces(string("   _ \n  /_\\\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(41111111)) == nospaces(string("  ___\n (_*_)\n (.,.)\n<( : )>\n ( : )")));
  
//NOSE\MOUTH TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(12111111)) == nospaces(string(" _===_\n (...)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(13111111)) == nospaces(string(" _===_\n (._.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(14111111)) == nospaces(string(" _===_\n (. .)\n<( : )>\n ( : )")));

//LEFT EYE TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11211111)) == nospaces(string(" _===_\n (o,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11311111)) == nospaces(string(" _===_\n (O,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11311111)) == nospaces(string(" _===_\n (-,.)\n<( : )>\n ( : )")));

 //RIGHT EYE TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11121111)) == nospaces(string(" _===_\n (.,o)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11131111)) == nospaces(string(" _===_\n (.,O)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11141111)) == nospaces(string(" _===_\n (.,-)\n<( : )>\n ( : )")));

//LEFT ARM TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11112111)) == nospaces(string(" _===_\n\\(.,.)\n ( : )>\n ( : )")));
    CHECK(nospaces(snowman(11113111)) == nospaces(string(" _===_\n (.,.)\n/( : )>\n ( : )")));
    CHECK(nospaces(snowman(11114111)) == nospaces(string(" _===_\n (.,.)\n ( : )>\n ( : )")));

//RIGHT ARM TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11111211)) == nospaces(string(" _===_\n (.,.)\n<( : )\\n ( : )")));
    CHECK(nospaces(snowman(11111311)) == nospaces(string(" _===_\n (.,.)/\n<( : )\n ( : )")));
    CHECK(nospaces(snowman(11111411)) == nospaces(string(" _===_\n (.,.)\n<( : ) \n ( : )")));

//TORSO TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11111121)) == nospaces(string(" _===_\n (.,.)\n<(] [)>\n ( : )")));
    CHECK(nospaces(snowman(11111131)) == nospaces(string(" _===_\n (.,.)\n<(> <)>\n ( : )")));
    CHECK(nospaces(snowman(11111141)) == nospaces(string("_===_\n(.,.)\n<(   )>\n( : )")));

//BASE TEST
    CHECK(nospaces(snowman(11111111)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n ( : )")));
    CHECK(nospaces(snowman(11111112)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n (\" \")")));
    CHECK(nospaces(snowman(11111113)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n (___)")));
    CHECK(nospaces(snowman(11111114)) == nospaces(string(" _===_\n (.,.)\n<( : )>\n (   )")));
}

//TESTS FOR BAD SNOWMAN
TEST_CASE("LESS THEN 8 DIGIT NUMBER") {
    CHECK_THROWS(nospaces(snowman(1)));
    CHECK_THROWS(nospaces(snowman(22)));
    CHECK_THROWS(nospaces(snowman(333)));
    CHECK_THROWS(nospaces(snowman(4444)));
    CHECK_THROWS(nospaces(snowman(12341)));
    CHECK_THROWS(nospaces(snowman(123412)));
    CHECK_THROWS(nospaces(snowman(1234123)));
}

TEST_CASE("MORE THEN 8 DIGIT NUMBER") {
    CHECK_THROWS(nospaces(snowman(111111111)));
    CHECK_THROWS(nospaces(snowman(221321321)));
    CHECK_THROWS(nospaces(snowman(221212321)));
    CHECK_THROWS(nospaces(snowman(221111321)));
    CHECK_THROWS(nospaces(snowman(444444321)));
}

TEST_CASE("NEGATIVE 8 DIGIT NUMBER") {
    CHECK_THROWS(nospaces(snowman(-11111111)));
    CHECK_THROWS(nospaces(snowman(-22132132)));
    CHECK_THROWS(nospaces(snowman(-44132132)));
    CHECK_THROWS(nospaces(snowman(-12211132)));
    CHECK_THROWS(nospaces(snowman(-14232132)));
    CHECK_THROWS(nospaces(snowman(-44122222)));
    CHECK_THROWS(nospaces(snowman(-33332132)));

}
TEST_CASE("NEGATIVE AND BIGGER THEN 4") {
    CHECK_THROWS(nospaces(snowman(-22132578)));
    CHECK_THROWS(nospaces(snowman(-22992132)));
    CHECK_THROWS(nospaces(snowman(-22189632)));
}

TEST_CASE("IIILEGAL 8 DIGIT NUMBER"){
    CHECK_THROWS(nospaces(snowman(29762578)));
    CHECK_THROWS(nospaces(snowman(22992666)));
    CHECK_THROWS(nospaces(snowman(78912355)));
}

