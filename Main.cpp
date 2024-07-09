#include <iostream>
#include "String.cpp"
#include "Matrix.cpp"

int main()
{
    Matrix w(5);
    std::cout << w;
    w.setMatrixIdenty(3, 76);
    std::cout << w;
    return 0;
}
