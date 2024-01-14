#include <iostream>
#include <memory>
#include "docview.hpp"

namespace hw {

class FrameworkPainter: public graphpr::IPainter
{
public:
    ~FrameworkPainter() = default;

    void drawLine(const graphpr::PointD &pos1, const graphpr::PointD &pos2) override final
    {
        std::cout << "FrameworkPainter::drawLine" << std::endl;
    }

    void drawRectangle(const graphpr::PointD &lt, const graphpr::PointD &rb) override final
    {
        std::cout << "FrameworkPainter::drawRectangle" << std::endl;
    }
};

DocView::DocView():
    m_editor {std::make_unique<hw::DocEditor>() }
{
}

void DocView::creteNew()
{
    m_editor->newDocument();
}

void DocView::handler()
{
    std::cout << "DocView::handler()" << std::endl;
    auto p = painter();
    m_doc->paint(p);
}

bool DocView::importFromFile(std::filesystem::path &&fileName)
{
    return m_editor->importFromFile(std::move(fileName));
}

bool DocView::exportToFile(const std::filesystem::path &fileName) const
{
    return m_editor->exportToFile(std::filesystem::path{fileName});
}

void DocView::addLine(const double x1, const double y1, const double x2, const double y2)
{
    m_editor->addLine(x1, y1, x2, y2);
}

void DocView::addRect(const double tlX, const double tlY, const double brX, const double brY)
{
    m_editor->addRect(tlX, tlY, brX, brY);
}

void DocView::setDocument(std::shared_ptr<Document> doc)
{
    std::cout << "DocView::setDocument" << std::endl;
    m_doc = doc;
    if (m_doc) {
        m_doc->addObserver(weak_from_this());
        m_editor->setDocument(m_doc);
        m_doc->paint(painter());
    }
}

std::shared_ptr<graphpr::IPainter> DocView::painter() const
{
    return std::make_shared<FrameworkPainter>();
}

bool DocView::removeItem(const std::size_t index)
{
    return m_editor->removeItem(index);
}

}