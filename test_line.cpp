#include "catch_amalgamated.hpp"
#include "line.h"
#include "point.h"

TEST_CASE("Line constructor and toString method", "[Line]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    REQUIRE(line.toString() == "Line(Point(1.0, 2.0), Point(3.0, 4.0))");

    Point p3(5.0, 6.0);
    Point p4(7.0, 8.0);
    Line line2(p3, p4);
    REQUIRE(line2.toString() == "Line(Point(5.0, 6.0), Point(7.0, 8.0))");
}

TEST_CASE("Line copy constructor", "[Line]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line1(p1, p2);
    Line line2(line1);
    REQUIRE(line2.toString() == "Line(Point(1.0, 2.0), Point(3.0, 4.0))");

    Point p3(5.0, 6.0);
    Point p4(7.0, 8.0);
    Line line3(p3, p4);
    Line line4(line3);
    REQUIRE(line4.toString() == "Line(Point(5.0, 6.0), Point(7.0, 8.0))");
}

TEST_CASE("Line equals method", "[Line]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Point p3(3.0, 4.0);
    Line line1(p1, p2);
    Line line2(p1, p3);
    REQUIRE(line1.equals(line2));

    Point p4(5.0, 6.0);
    Point p5(7.0, 8.0);
    Line line3(p4, p5);
    Line line4(p3, p4);
    REQUIRE(!line3.equals(line4));
}

TEST_CASE("Line flip method", "[Line]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    line.flip();
    REQUIRE(line.toString() == "Line(Point(-1.0, -2.0), Point(-3.0, -4.0))");

    Point p3(5.0, 6.0);
    Point p4(7.0, 8.0);
    Line line2(p3, p4);
    line2.flip();
    REQUIRE(line2.toString() == "Line(Point(-5.0, -6.0), Point(-7.0, -8.0))");
}

TEST_CASE("Line move method", "[Line]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    line.move(1.0, 1.0);
    REQUIRE(line.toString() == "Line(Point(2.0, 3.0), Point(4.0, 5.0))");

    Point p3(5.0, 6.0);
    Point p4(7.0, 8.0);
    Line line2(p3, p4);
    line2.move(2.0, 2.0);
    REQUIRE(line2.toString() == "Line(Point(7.0, 8.0), Point(9.0, 10.0))");
}
TEST_CASE("Line equals with reversed endpoints", "[Line]") {
    Point p1(0.0, 0.0);
    Point p2(1.0, 1.0);

    Line line1(p1, p2);
    Line line2(p2, p1);

    REQUIRE(line1.equals(line2));
}
