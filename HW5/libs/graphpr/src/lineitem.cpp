#include <iostream>
#include "lineitem.hpp"

namespace graphpr {

void LineItem::paint(std::shared_ptr<IPainter> painter)
{
    std::cout << "LineItem::paint" << std::endl;
    
    if (painter)
        painter->drawLine(m_pos1, m_pos2);
}

RectD LineItem::boundingRect() const
{
    return RectD{std::min(m_pos1.x, m_pos2.x), std::min(m_pos1.y, m_pos2.y),
        std::max(m_pos1.x, m_pos2.x), std::max(m_pos1.y, m_pos2.y)};
}
}
