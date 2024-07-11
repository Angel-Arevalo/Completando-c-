#include <iostream>
#include "String.cpp"
#include "Matrix.cpp"

int main()
{
    Matrix z;
    z.setRandmatrix(4);
    std::cout << z;
    Matrix::getMatrixInv(z);

    return 0;
}
