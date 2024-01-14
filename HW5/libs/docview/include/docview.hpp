#pragma once

#include <behavioral/observer.hpp>
#include <doceditor.hpp>

namespace hw {

/// @brief Класс для визуальной работы с документом
class DocView: public patterns::Observer<DocView>
{
public:
    /// @brief конструктор
    DocView();
    /// @brief деструктор
    ~DocView() override = default;

    /// @brief создание нового графического документа
    void creteNew();

    /// @brief обработчик событий документа(модели)
    void handler();

    /// @brief импорт документа из файла
    /// @param fileName имя файла
    /// @return true, если импорт произведён успешно, иначе false
    bool importFromFile(std::filesystem::path &&fileName);

    /// @brief экспорт документа в файл
    /// @param fileName имя файла экспорта
    /// @return true, еслли экспорт произведён успешно, иначе - false
    bool exportToFile(const std::filesystem::path &fileName) const;

    /// @brief добавление линии
    /// @param x1 координата x первой точки
    /// @param y1 координата y первой точки
    /// @param x2 координата x второй точки
    /// @param y2 координата y второй точки
    void addLine(const double x1, const double y1, const double x2, const double y2);

    /// @brief добавление прямоугольника
    /// @param tlX верхняя левая координата x
    /// @param tlY верхняя левая координата y
    /// @param brX нижняя правая координата x
    /// @param brY нижняя правая координата y
    void addRect(const double tlX, const double tlY, const double brX, const double brY);

    /// @brief установка документа(модели)
    /// @param doc редактируемый документ(модель)
    void setDocument(std::shared_ptr<Document> doc);

    /// @brief удаление элемента
    /// @param index порядковый номер элемента в документе
    /// @return true, если элемент удалён, иначе false
    bool removeItem(const std::size_t index);

private:
    std::shared_ptr<graphpr::IPainter> painter() const;
    std::unique_ptr<hw::DocEditor> m_editor;
    std::shared_ptr<Document> m_doc;
};

}