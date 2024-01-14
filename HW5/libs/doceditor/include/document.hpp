#pragma once

#include <graphicsitem.hpp>
#include <behavioral/observable.hpp>

namespace hw {

/// @brief класс документа с графическими примитивами
class Document: public patterns::Observable
{
public:
    /// @brief конструктор по умолчанию
    Document();

    /// @brief конструктор перемещения
    /// @param  
    Document(Document &&) noexcept = default;

    /// @brief конструктор копирования
    /// @param other 
    Document(const Document &other);

    /// @brief деструктор
    ~Document() = default;

    /// @brief добавление графическго элемента
    /// @param item 
    void addGraphicsItem(std::shared_ptr<graphpr::GraphicsItem> item);

    /// @brief отрисовка документа с использованием IPainter
    /// @param painter интерфес IPainter
    void paint(std::shared_ptr<graphpr::IPainter> painter) const;

    /// @brief установка графических элементов
    /// @param items 
    void setGraphicsItems(graphpr::GraphicsItems &&items);

    /// @brief удаление элемента
    /// @param index порядковый номер элемента в документе
    /// @return true, если элемент удалён, иначе false
    bool removeItem(const std::size_t index);

    /// @brief сбрасывает состояние к начальном, эквивалентно созданию нового документа
    void reset();

    struct Pimpl;

    struct PimplDeleter
    {
        void operator()(Pimpl *p) const;
    };

    std::unique_ptr<Pimpl, PimplDeleter> m_d;
};

}