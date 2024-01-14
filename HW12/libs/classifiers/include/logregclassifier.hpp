#pragma once

#include "ibinaryclassifier.hpp"

namespace fashion {

///
/// \brief The LogregClassifier class Файл классификатора для логистической регрессии
///
class LogregClassifier : public IBinaryClassifier
{
public:
    using CoefsType = FeaturesType;

    LogregClassifier(CoefsType &&coef);

    float predictProbability(const FeaturesType &feat) const override;

protected:
    CoefsType m_coef;
};

}
