// test_group.cpp
#include "catch_amalgamated.hpp"
#include "group.h"
#include "line.h"
#include "triangle.h"
#include "quadrilateral.h"
#include "point.h"

TEST_CASE("Group constructor and toString method", "[Group]") {
    Group group;
    REQUIRE(group.toString() == "Group()");

    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    group.add(&line);
    REQUIRE(group.toString() == "Group(Line(Point(1.0, 2.0), Point(3.0, 4.0)), )");
}

TEST_CASE("Group copy constructor", "[Group]") {
    Group group1;
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    group1.add(&line);
    Group group2(group1);
    REQUIRE(group2.toString() == "Group(Line(Point(1.0, 2.0), Point(3.0, 4.0)), )");
}

TEST_CASE("Group equals method", "[Group]") {
    Group group1;
    Group group2;
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    group1.add(&line);
    group2.add(&line);
    REQUIRE(group1.equals(group2));
}

TEST_CASE("Group flip method", "[Group]") {
    Group group;
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    group.add(&line);
    group.flip();
    REQUIRE(group.toString() == "Group(Line(Point(-1.0, -2.0), Point(-3.0, -4.0)), )");

    Point p3(5.0, 6.0);
    Point p4(7.0, 8.0);
    Line line2(p3, p4);
    group.add(&line2);
    group.flip();
    REQUIRE(group.toString() == "Group(Line(Point(1.0, 2.0), Point(3.0, 4.0)), Line(Point(-5.0, -6.0), Point(-7.0, -8.0)), )");
}

TEST_CASE("Group move method", "[Group]") {
    Group group;
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    group.add(&line);
    group.move(1.0, 1.0);
    REQUIRE(group.toString() == "Group(Line(Point(2.0, 3.0), Point(4.0, 5.0)), )");

    Point p3(5.0, 6.0);
    Point p4(7.0, 8.0);
    Line line2(p3, p4);
    group.add(&line2);
    group.move(2.0, 2.0);
    REQUIRE(group.toString() == "Group(Line(Point(4.0, 5.0), Point(6.0, 7.0)), Line(Point(7.0, 8.0), Point(9.0, 10.0)), )");
}

TEST_CASE("Group getSurface method", "[Group]") {
    Group group;
    Point p1(0.0, 0.0);
    Point p2(4.0, 0.0);
    Point p3(0.0, 3.0);
    Point p4(4.0, 8.0);
    Point p5(4.0, 0.0);
    Point p6(4.0, 3.0);
    Point p7(0.0, 3.0);
    Point p8(0.0, 0.0);

    Triangle triangle1(p1, p2, p3);
    Quadrilateral quad1(p1, p2, p4, p3);
    group.add(&triangle1);
    group.add(&quad1);
    REQUIRE(group.getSurface() == Catch::Approx(28.0));

    Quadrilateral quad2(p4, p5, p6, p8);
    Triangle triangle2(p8, p5, p7);
    group.add(&quad2);
    group.add(&triangle2);
    REQUIRE(group.getSurface() == Catch::Approx(44.0));
}
TEST_CASE("Group remove method", "[Group]") {
    Group group;
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Line line(p1, p2);
    group.add(&line);

    // upewniamy się, że obiekt jest w grupie
    REQUIRE(group.toString() == "Group(Line(Point(1.0, 2.0), Point(3.0, 4.0)), )");

    // usuwamy
    group.remove(&line);

    // grupa powinna być pusta
    REQUIRE(group.toString() == "Group()");
}
