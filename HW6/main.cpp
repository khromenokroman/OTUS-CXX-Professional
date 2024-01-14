#include <assert.h>
#include <iostream>
#include <matrix.hpp>
#include "version.h"

using namespace std;

int main()
{
    using namespace std;

    cout << "Application version: " << PROJECT_VERSION << endl;

    Matrix<int, 0> matrix;
    for (std::size_t i = 0; i < 10; ++i) {
        matrix[i][i] = i;
        matrix[i][9 - i] = 9 - i;
    }

    for (std::size_t r = 1; r < 9; ++r) {
        std::cout << matrix[r][1];
        for (std::size_t c = 2; c < 9; ++c) {
            std::cout << " " << matrix[r][c];
        }
        std::cout << std::endl;
    }

    std::cout << matrix.size() << std::endl;

    return 0;
}
