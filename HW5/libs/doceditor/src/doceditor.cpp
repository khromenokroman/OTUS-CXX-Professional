#include <lineitem.hpp>
#include <rectitem.hpp>
#include "doceditor.hpp"
#include "docimporterfabric.hpp"
#include "svgexporter.hpp"

namespace hw {
    
std::shared_ptr<Document> DocEditor::newDocument()
{
    if (m_document)
        m_document->reset();
    
    return m_document;
}

bool DocEditor::importFromFile(std::filesystem::path &&fileName)
{
    std::cout << "DocEditor::importFromFile " << fileName << std::endl;

    if (!m_document)
        return false;

    auto importer = makeImporter(fileName);
    if (importer) {
        auto [res, items] = importer->importDoc(std::move(fileName));
        if (res)
            m_document->setGraphicsItems(std::move(items));
        else
            m_document->reset();

        return res;
    }
    return false;
}

bool DocEditor::exportToFile(std::filesystem::path &&fileName) const
{
    std::cout << "DocEditor::exportToFile " << fileName << std::endl;

    SvgExporter exp;
    return exp.exportToFile(std::move(fileName), m_document);
}

void DocEditor::addLine(const double x1, const double y1, const double x2, const double y2)
{
    std::cout << "DocEditor::addLine" << std::endl;

    using namespace graphpr;
    if (m_document)
        m_document->addGraphicsItem(std::make_unique<LineItem>(PointD{x1, y1}, PointD{x2, y2}));
}

void DocEditor::addRect(const double tlX, const double tlY, const double brX, const double brY)
{
    std::cout << "DocEditor::addRect" << std::endl;
    using namespace graphpr;
    if (m_document)
        m_document->addGraphicsItem(std::make_unique<RectItem>(PointD{tlX, tlY}, PointD{brX, brY}));
}

void DocEditor::setDocument(std::shared_ptr<Document> doc)
{
    m_document = doc;
}
bool DocEditor::removeItem(const std::size_t index)
{
    if (m_document)
        return m_document->removeItem(index);

    return false;
}

}
