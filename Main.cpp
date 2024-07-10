#include <iostream>
#include "String.cpp"
#include "Matrix.cpp"

int main()
{
    Matrix w;
    Matrix z;
    w.setMatrixIdenty(4, 5);
    z.setMatrixIdenty(4, -5);
    std::cout << w << z << std::endl;
    std::cout << (w + z);
    return 0;
}
