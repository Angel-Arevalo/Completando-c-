#include <iostream>
#include "String.cpp"

int main()
{
    String x = "HELLO";
    String y("hello");
    bool m = x /= y;
    std::cout << m << "\n\n";
    std::cout << x.getlength() << "\n\n";
    std::cout << x << "\n\n";
    std::cout << y.getlength() << "\n\n";
    std::cout << y << "\n\n";
    std::cout << x[2]<< "\n\n";
    return 0;
}
