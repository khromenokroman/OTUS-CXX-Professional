#pragma once

#include <filesystem>
#include <tuple>
#include <graphicsitem.hpp>

/// @brief абстрактный интерфейс реализации импорта документа
struct IDocImporter
{
    /// @brief виртуальный деструктор
    virtual ~IDocImporter() = default;

    /// @brief чистовиртуальная функция реалзации импорта из файла
    /// @param путь к файлу
    /// @return tuple с первым параметром true, если удалось импортировать из файла, в противном случае false
    /// и сами графические элементы
    virtual std::tuple<bool, graphpr::GraphicsItems> importDoc(std::filesystem::path &&) = 0;

};
