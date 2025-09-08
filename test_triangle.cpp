//
// Created by nwaszkowiak on 26.11.24.
//
#include "catch_amalgamated.hpp"
#include "triangle.h"
#include "point.h"

TEST_CASE("Triangle constructor and toString method", "[Triangle]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Point p3(5.0, 6.0);
    Triangle triangle(p1, p2, p3);
    REQUIRE(triangle.toString() == "Triangle(Point(1.0, 2.0), Point(3.0, 4.0), Point(5.0, 6.0))");

    Point p4(7.0, 8.0);
    Point p5(9.0, 10.0);
    Point p6(11.0, 12.0);
    Triangle triangle2(p4, p5, p6);
    REQUIRE(triangle2.toString() == "Triangle(Point(7.0, 8.0), Point(9.0, 10.0), Point(11.0, 12.0))");
}

TEST_CASE("Triangle copy constructor", "[Triangle]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Point p3(5.0, 6.0);
    Triangle triangle1(p1, p2, p3);
    Triangle triangle2(triangle1);
    REQUIRE(triangle2.toString() == "Triangle(Point(1.0, 2.0), Point(3.0, 4.0), Point(5.0, 6.0))");

    Point p4(7.0, 8.0);
    Point p5(9.0, 10.0);
    Point p6(11.0, 12.0);
    Triangle triangle3(p4, p5, p6);
    Triangle triangle4(triangle3);
    REQUIRE(triangle4.toString() == "Triangle(Point(7.0, 8.0), Point(9.0, 10.0), Point(11.0, 12.0))");
}

TEST_CASE("Triangle equals method", "[Triangle]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Point p3(5.0, 6.0);
    Triangle triangle1(p1, p2, p3);
    Triangle triangle2(p1, p2, p3);
    REQUIRE(triangle1.equals(triangle2));

    Point p4(7.0, 8.0);
    Point p5(9.0, 10.0);
    Point p6(11.0, 12.0);
    Triangle triangle3(p4, p5, p6);
    Triangle triangle4(p4, p5, p6);
    REQUIRE(triangle3.equals(triangle4));
}

TEST_CASE("Triangle flip method", "[Triangle]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Point p3(5.0, 6.0);
    Triangle triangle(p1, p2, p3);
    triangle.flip();
    REQUIRE(triangle.toString() == "Triangle(Point(-1.0, -2.0), Point(-3.0, -4.0), Point(-5.0, -6.0))");

    Point p4(7.0, 8.0);
    Point p5(9.0, 10.0);
    Point p6(11.0, 12.0);
    Triangle triangle2(p4, p5, p6);
    triangle2.flip();
    REQUIRE(triangle2.toString() == "Triangle(Point(-7.0, -8.0), Point(-9.0, -10.0), Point(-11.0, -12.0))");
}

TEST_CASE("Triangle move method", "[Triangle]") {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Point p3(5.0, 6.0);
    Triangle triangle(p1, p2, p3);
    triangle.move(1.0, 1.0);
    REQUIRE(triangle.toString() == "Triangle(Point(2.0, 3.0), Point(4.0, 5.0), Point(6.0, 7.0))");

    Point p4(7.0, 8.0);
    Point p5(9.0, 10.0);
    Point p6(11.0, 12.0);
    Triangle triangle2(p4, p5, p6);
    triangle2.move(2.0, 2.0);
    REQUIRE(triangle2.toString() == "Triangle(Point(9.0, 10.0), Point(11.0, 12.0), Point(13.0, 14.0))");
}

TEST_CASE("Triangle getSurface method", "[Triangle]") {
    Point p1(0.0, 0.0);
    Point p2(4.0, 0.0);
    Point p3(0.0, 3.0);
    Triangle triangle(p1, p2, p3);
    REQUIRE(triangle.getSurface() == Catch::Approx(6.0));

    Point p4(0.0, 0.0);
    Point p5(3.0, 0.0);
    Point p6(0.0, 4.0);
    Triangle triangle2(p4, p5, p6);
    REQUIRE(triangle2.getSurface() == Catch::Approx(6.0));
}
TEST_CASE("Triangle equals with different vertex order", "[Triangle]") {
    Point p1(0.0, 0.0);
    Point p2(1.0, 0.0);
    Point p3(0.0, 1.0);

    Triangle t1(p1, p2, p3);
    // ta sama figura, ale kolejność wierzchołków zmieniona
    Triangle t2(p3, p1, p2);

    REQUIRE(t1.equals(t2));
}
