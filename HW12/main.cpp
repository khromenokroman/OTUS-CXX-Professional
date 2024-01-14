#include <iostream>
#include <utility>
#include <logregclassifier.hpp>
#include <utils.hpp>
#include "version.h"

int main(int argc, char *argv[])
{
    using namespace fashion;

    std::cout << "fashion_mnist version: " << PROJECT_VERSION << std::endl;

    if (argc != 3) {
        std::cerr << "Usage: fashion_mnist <verification_csv> <logreg_coef>" << std::endl;
        return 1;
    }

    std::vector<LogregClassifier> classifiers;

    { // считывание коэффициентов и создание классификаторов
        std::ifstream coefInput(argv[2]);
        LogregClassifier::CoefsType coefs;
        while (readLogRegressionCoeficients(coefInput, coefs))
            classifiers.emplace_back(LogregClassifier(std::exchange(coefs, {})));
    }

    std::ifstream dataInput(argv[1]);

    LogregClassifier::FeaturesType features;
    int targetClass;
    std::size_t totalCount = 0;
    std::size_t rightAnswersCount = 0;

    while (readFeatures(dataInput, features, targetClass)) {

        ++totalCount;

        float maxResult = -1;
        int maxResultClass = 0;

        for (size_t i = 0; i < classifiers.size(); ++i) {
            auto result = classifiers[i].predictProbability(features);
            if (result > maxResult) {
                maxResult = result;
                maxResultClass = i;
            }
        }

        if (maxResultClass == targetClass)
            ++rightAnswersCount;
    }

    float accuracy = 0.0f;
    if (totalCount > 0)
        accuracy = static_cast<float>(rightAnswersCount) / totalCount;

    std::cout << accuracy << std::endl;

    return 0;
}
