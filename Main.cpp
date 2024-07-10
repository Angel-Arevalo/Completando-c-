#include <iostream>
#include "String.cpp"
#include "Matrix.cpp"

int main()
{
    Matrix w;
    Matrix z;
    w.setRandmatrix(4, 2);
    z.setRandmatrix(2, 5);
    std::cout << w;
    std::cout << z;
    z = z * w;
    std::cout << z;
    return 0;
}
