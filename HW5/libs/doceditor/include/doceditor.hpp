#pragma once

#include <filesystem>
#include "document.hpp"

namespace hw {

/// @brief класс -контроллер для управления документом(моделью)
class DocEditor
{
public:
    /// @brief Создание нового документа
    std::shared_ptr<Document> newDocument();

    bool importFromFile(std::filesystem::path &&fileName);

    /// @brief экспорт документа в файл
    /// @param fileName имя файла экспорта
    /// @return true, еслли экспорт произведён успешно, иначе - false
    bool exportToFile(std::filesystem::path &&fileName) const;

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

    void setDocument(std::shared_ptr<Document> doc);

    /// @brief удаление элемента
    /// @param index порядковый номер элемента в документе
    /// @return true, если элемент удалён, иначе false
    bool removeItem(const std::size_t index);

private:
    std::shared_ptr<Document> m_document;
};

}