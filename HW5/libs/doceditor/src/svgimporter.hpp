#pragma once

#include <iostream>
#include "idocimporter.hpp"

namespace hw {

/// @brief класс импорта документа
struct SvgImporter: IDocImporter
{
    /// @brief импорт svg-документа из файла
    /// @param path путь к файлу
    /// @return true, если файл существует, иначе false
    std::tuple<bool, graphpr::GraphicsItems> importDoc(std::filesystem::path &&path) override final
    {
        std::cout << "SvgImporter::importDoc "<< path << std::endl;

        namespace fs = std::filesystem;
        return std::make_tuple(fs::exists(path) && path.extension() == ".svg", graphpr::GraphicsItems{});
    }
};

}
