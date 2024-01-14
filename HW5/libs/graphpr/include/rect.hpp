#pragma once

#include "point.hpp"

namespace graphpr {

/// @brief Описание координат прямоугольника
/// @tparam T тип координаты точки
template <typename T>
class Rect
{
public:
    Rect() = default;
    Rect(const Point<T> &topLeft, const Point<T> &bottomRight);
    Rect(const T tlX, const T tlY, const T brX, const T brY);
    ~Rect() = default;
private:
    Point<T> m_topLeft;
    Point<T> m_bottomRight;
};

/// @brief Прямоугольник с типом координаты double
using RectD = Rect<double>;

/// @brief Прямоугольник с типом координаты int
using RectInt = Rect<int>;

template <typename T>
inline Rect<T>::Rect(const Point<T> &topLeft, const Point<T> &bottomRight):
    m_topLeft {topLeft}, m_bottomRight {bottomRight}
{
}

template <typename T>
inline Rect<T>::Rect(const T tlX, const T tlY, const T brX, const T brY):
    Rect(Point<T>{tlX, tlY}, Point<T>{brX, brY})
{
}
}