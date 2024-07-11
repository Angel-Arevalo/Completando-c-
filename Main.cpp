#include <iostream>
#include "String.cpp"
#include "Matrix.cpp"

int main()
{
    Matrix w;
    Matrix z;
    w.setRandmatrix(7);
    std::cout << w;
    double f = Matrix::getDeterminant(w);
    std::cout << f;
    return 0;
}
