#include <list>
#include "document.hpp"


namespace hw {
    
    struct Document::Pimpl final
    {
        graphpr::GraphicsItems items;
    };

    Document::Document():
        m_d (std::unique_ptr<Pimpl, PimplDeleter>(new Pimpl, PimplDeleter()))
    {
    }

    void Document::addGraphicsItem(std::shared_ptr<graphpr::GraphicsItem> item)
    {
        m_d->items.emplace_back(std::move(item));
        notityEvent();
    }

    void Document::paint(std::shared_ptr<graphpr::IPainter> painter) const
    {
        for (auto &&item : m_d->items)
        {
            item->paint(painter);
        }
        
    }

    void Document::setGraphicsItems(graphpr::GraphicsItems &&items)
    {
        m_d->items = std::move(items);
        notityEvent();
    }
    bool Document::removeItem(const std::size_t index)
    {
        if (index < m_d->items.size()) {
            m_d->items.erase(m_d->items.cbegin() + index);
            notityEvent();
            return true;
        }

        return false;
    }

    void Document::reset()
    {
        m_d->items.clear();
        notityEvent();
    }

    void Document::PimplDeleter::operator()(Pimpl *p) const
    {
        delete p;
    }

}
