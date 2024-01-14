#include <iostream>
#include <doceditor.hpp>
#include <docview.hpp>
#include <lineitem.hpp>
#include "version.h"

using namespace std;

int main()
{
    using namespace std;

    cout << "My app version: " << PROJECT_VERSION << endl;

    // создаётся документ(модель)
    auto doc = std::make_shared<hw::Document>();
    // добавляются данные, которые вьюшка должна будет отрисовать последобавления этого документа во view
    doc->addGraphicsItem(std::make_shared<graphpr::LineItem>(graphpr::PointD{0.0, 0.0}, graphpr::PointD{1.1, 2.1}));

    // shared_ptr из-за наследования от std::enable_shared_from_this для передачи наблюдателя в документ в качестве weak_ptr
    auto docView = std::make_shared<hw::DocView>();
    docView->setDocument(doc);

    // добавление графических примитивов
    docView->addLine(1.0, 1.2, 2.0, -1.7);
    docView->addRect(2.0, 2.0, -2.0, -1.7);

    // удаление первого элемента
    docView->removeItem(0);

    // импорт из файла
    docView->importFromFile("/tmp/image.svg");

    // экспорт в файл
    docView->exportToFile("/tmp/new_image.svg");

    return 0;
}
