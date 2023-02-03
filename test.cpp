#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do
                          // this in one cpp file
#include "Circle.h"
#include "catch.hpp"

Point p1{3, 2};
Point p2{5, 2};
Point p3{10, 7};
Point p4{-2, 5};
Circle c1(p1, 5);
Circle c2(p2, 3);
Circle c3(p3, -6);
Circle c4(p4, 0);

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(5) == 120);
}

TEST_CASE("Points are assigned", "[point]")
{
    REQUIRE(c1.get_center().x == p1.x);
    REQUIRE(c1.get_center().y == p1.y);
}
TEST_CASE("Radius is assigned", "[radius]")
{
    REQUIRE(c1.get_radius() == 5);
    REQUIRE(c3.get_radius() == 0);
}

TEST_CASE("Overlap is checked", "[overlap]")
{
    REQUIRE(c1.Overlaps(c2) == true);
    REQUIRE(c1.Overlaps(c1) == true);
    REQUIRE(c1.Overlaps(c3) == false);
    REQUIRE(c2.Overlaps(c3) == false);
}

TEST_CASE("Area is calculated", "[area]")
{
    REQUIRE(c1.CalculateArea() == 78);
    REQUIRE(c2.CalculateArea() == 28);
    REQUIRE(c3.CalculateArea() == 0);
}

TEST_CASE("Expand tested", "[expand]")
{
    c1.Expand();
    REQUIRE(c1.get_radius() == 6);
    REQUIRE(c1.get_center().x == 3);
    REQUIRE(c1.get_center().y == 2);
    c3.Expand();
    REQUIRE(c3.get_radius() == 1);
}

TEST_CASE("Shrink tested", "[shrink]")
{
    c2.Shrink();
    REQUIRE(c2.get_radius() == 2);
    REQUIRE(c2.get_center().x == 5);
    REQUIRE(c2.get_center().y == 2);
    c4.Shrink();
    REQUIRE(c4.get_radius() == 0);
}
