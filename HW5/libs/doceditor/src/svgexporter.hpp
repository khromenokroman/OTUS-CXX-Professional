#include <iostream>
#include "idocexporter.hpp"

namespace hw {

class SvgExporter: public IDocExporter
{
public:
    ~SvgExporter() override = default;

    bool exportToFile(std::filesystem::path &&fileName, std::shared_ptr<const Document> doc) override final
    {
        std::cout << "SvgExporter::exportToFile " << fileName << std::endl;
        namespace fs = std::filesystem;
        if (!doc)
            return false;

        std::cout << "SvgExporter::exportToFile: document imported" << std::endl;
        return true;    
    }
};

}