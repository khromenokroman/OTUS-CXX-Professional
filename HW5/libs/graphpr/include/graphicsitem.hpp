#pragma once

#include <memory>
#include <vector>
#include "rect.hpp"
#include "ipainter.hpp"

namespace graphpr {

/// @brief Базовый графический элемент
class GraphicsItem
{
public:
    virtual ~GraphicsItem() = default;
    
    /// @brief рисует графический элемент, используя painter
    /// @param painter указатель на контекст рисования
    virtual void paint(std::shared_ptr<IPainter> painter) = 0;

    /// @brief внешние границы элемента
    /// @return RectD
    virtual RectD boundingRect() const = 0;


    /// @brief z-уровень расположения элемента
    /// @return 
    int zValue() const noexcept { return m_zValue; }


    /// @brief установка z-уровня расположения элемента
    /// @param value 
    void setZValue(const int value) noexcept
    {
        if (value == m_zValue)
            return;

        m_zValue = value;    
    }

private:
    int m_zValue {1}; // глубина расположения элемента
};

/// @brief вектор shared_ptr графических элементов
using GraphicsItems = std::vector<std::shared_ptr<GraphicsItem>>;

}