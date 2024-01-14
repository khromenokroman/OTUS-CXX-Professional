#include "docimporterfabric.hpp"
#include "svgimporter.hpp"

namespace hw {

std::unique_ptr<IDocImporter> makeImporter(const std::filesystem::path &path)
{
    const auto ext = path.extension();
    if (ext == ".svg")
        return std::make_unique<SvgImporter>();

    return nullptr;
}

}
