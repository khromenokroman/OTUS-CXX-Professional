#pragma once

namespace graphpr {

template <typename T>
struct Point
{
    Point(T x, T y): x{x}, y{y} {}
    Point() = default;
    Point(const Point &) = default;
    Point(Point &&) = default;

    T x {};
    T y {};
};

using PointInt = Point<int>;

using PointD = Point<double>;

}
