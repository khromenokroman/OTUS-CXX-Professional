#pragma once

#include "idocimporter.hpp"

namespace hw {
    /// @brief фабрика для создания импортера элементов графического документа по расширению файла
    /// @param path путь к файлу
    /// @return unique_ptr на экземпляр класса, если найдено соответствие, в противном случае nullptr
    std::unique_ptr<IDocImporter> makeImporter(const std::filesystem::path &path);    
}