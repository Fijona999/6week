#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"DocTest.h"
#include"Rooms.h"

TEST_CASE("test"){
  Rooms:Colour Rooms(3);
  Rooms:setColour("green");
  CHECK(Rooms.getColour() == std::vector<std::string>("red");
} 
