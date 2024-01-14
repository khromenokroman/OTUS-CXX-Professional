#pragma once

#include "graphicsitem.hpp"
#include "point.hpp"

namespace graphpr {

/// @brief Элемент, отвечающий за отображение линии
class LineItem: public GraphicsItem
{
public:
    LineItem(const PointD &pos1, const PointD &pos2): m_pos1 {pos1}, m_pos2 {pos2} {}
    ~LineItem() override = default;

    /// @brief рисует графический элемент, используя painter
    /// @param painter указатель на контекст рисования
    void paint(std::shared_ptr<IPainter> painter) override;

    /// @brief внешние границы элемента
    /// @return RectD
    RectD boundingRect() const override;

private:
    PointD m_pos1;
    PointD m_pos2;
};

}