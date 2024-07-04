#include <iostream>
#include "String.cpp"
#include "VectorRn.cpp"

int main()
{
    VectorRn<int> v(4, 1, 2, 4, 5);
    VectorRn<double> w(5, 4.3, 1.928, 12.019271, 3.141516, 2.7115);
    std::cout << w << " " << v;
    return 0;
}
