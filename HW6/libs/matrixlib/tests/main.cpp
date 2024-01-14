#include <gtest/gtest.h>
#include <matrix.hpp>

/// @brief Тесты для двумерной матрицы
/// @param  
/// @param  
TEST(MatrixLibTest, TwoDimTest)
{
    constexpr int defaultValue = -1;

    // изменяемая матрица
    Matrix<int, defaultValue> matrix;
    EXPECT_EQ(matrix.size(), 0);

    auto a = matrix[0][0];
    EXPECT_EQ(a, defaultValue);
    EXPECT_EQ(matrix.size(), 0);

    matrix[100][100] = 314;
    EXPECT_EQ(matrix[100][100], 314);
    EXPECT_EQ(matrix.size(), 1);

    // константная матрица
    const auto &mRef = matrix;

    EXPECT_EQ(matrix.size(), 1);

    const auto ca = matrix[0][0];
    EXPECT_EQ(ca, defaultValue);
    EXPECT_EQ(matrix.size(), 1);

    EXPECT_EQ(matrix[100][100], 314);
    EXPECT_EQ(matrix.size(), 1);
}

// Тесты для двумерной матрицы
TEST(MatrixLibTest, OneDimTest)
{
    constexpr int defaultValue = -1;
    Matrix<int, defaultValue, 1> matrix;
    EXPECT_EQ(matrix.size(), 0);

    const auto a = matrix[0];
    EXPECT_EQ(a, defaultValue);
    EXPECT_EQ(matrix.size(), 0);

    matrix[100] = 314;
    EXPECT_EQ(matrix[100], 314);
    EXPECT_EQ(matrix.size(), 1);
}
