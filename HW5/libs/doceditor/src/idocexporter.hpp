#pragma once

#include <memory>
#include <filesystem>
#include <tuple>
#include "document.hpp"

namespace hw {

/// @brief абстрактный интерфейс реализации импорта документа
struct IDocExporter
{
    /// @brief виртуальный деструктор
    virtual ~IDocExporter() = default;

    /// @brief чистовиртуальная функция реалзации экспорта в файл
    /// @param путь к файлу 
    /// @param умный указатель на константный объект документа 
    /// @return true, если экспорт произошёл успешно, false - в противном случае
    virtual bool exportToFile(std::filesystem::path &&, std::shared_ptr<const Document>) = 0;

};

}