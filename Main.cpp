#include <iostream>
#include "String.cpp"
#include "Matrix.cpp"

int main()
{
    Matrix z;
    Matrix::readEntriesCin(z);
    std::cout << z;
    Matrix w = Matrix::getMatrixInv(z);
    std::cout << w;
    std::cout << w*z;

    return 0;
}
