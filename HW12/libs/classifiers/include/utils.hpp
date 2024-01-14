#pragma once

#include <fstream>
#include <sstream>
#include <vector>

namespace fashion {

///
/// \brief readLogRegressionCoeficients Считывание коэффициентов логистической регрессии
/// \param stream Файловый поток
/// \param coefs Контейнер для коэффициентов
/// \return
///
bool readLogRegressionCoeficients(std::istream &stream, std::vector<float> &coefs);

///
/// \brief readFeatures Считывание проверочной выборки
/// \param stream Файловый поток
/// \param features Проверочная выборка для класса \param targetClass
/// \param targetClass Класс
/// \return true, если считываение прошло успешно, иначе false
///
bool readFeatures(std::istream &stream, std::vector<float> &features, int &targetClass);


}
