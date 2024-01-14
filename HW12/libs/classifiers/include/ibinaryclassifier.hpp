#pragma once

#include <vector>

namespace fashion {

///
/// \brief The IBinaryClassifier class Интерфейс класса классификатора
///
class IBinaryClassifier
{
public:
    using FeaturesType = std::vector<float>;

    virtual ~IBinaryClassifier() = default;

    virtual float predictProbability(const FeaturesType &) const = 0;
};

}
