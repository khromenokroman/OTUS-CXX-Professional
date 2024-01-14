#pragma once

#include <iostream>
#include "graphicsitem.hpp"
#include "point.hpp"

namespace graphpr {

/// @brief Элемент, отвечающий за отображение линии
class RectItem: public GraphicsItem
{
public:
    RectItem(const PointD &tl, const PointD &br): m_tl {tl}, m_br {br} {}
    ~RectItem() override = default;

    /// @brief рисует графический элемент, используя painter
    /// @param painter указатель на контекст рисования
    void paint(std::shared_ptr<IPainter> painter) override final
    {
        std::cout << "RectItem::paint" << std::endl;
        if (painter)
            painter->drawRectangle(m_tl, m_br);
    }

    /// @brief внешние границы элемента
    /// @return RectD
    RectD boundingRect() const override final
    {
        return RectD{m_tl, m_br};
    }

private:
    PointD m_tl;
    PointD m_br;
};

}