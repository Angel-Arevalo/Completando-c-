#include <iostream>
#include "String.cpp"
#include "VectorRn.cpp"

int main()
{
    VectorRn<int> v(3, 1, 0, 0);
    VectorRn<int> w(3, 0, 1, 0);
    std::cout << (w % v);
    return 0;
}
